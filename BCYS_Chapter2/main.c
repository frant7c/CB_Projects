#include <stdio.h>
#include <stdlib.h>

void make_primes()
{
    FILE *file;
    unsigned int i, j;
    unsigned int max_num = -1;
    unsigned int primes[70000];
    int prime_cnt = 2;
    int is_prime = 1;

    primes[0] = 2;
    primes[1] = 3;

    for(i = 5; i < 100000; i += 2)
    {
        is_prime = 1;
        for(j = 0; primes[j] * primes[j] <= i; j++)
        {
            if(i % primes[j] == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if(is_prime)
        {
            primes[prime_cnt++] = i;
        }
    }

    file = fopen("primes.txt", "w+");
    if(NULL == file)
    {
        printf("File does not exist.");
        return;
    }
    for(i = 0; i < prime_cnt; i++)
    {
        fprintf(file, "%u ", primes[i]);
        if((i + 1) % 8 == 0)
        {
            fprintf(file, "\n");
        }
    }
    fclose(file);
}

/*��ͨ������������steps = 2695696 prime_cnt = 9592*/
void make_primes1()
{
    unsigned int max_num = -1;
    unsigned int primes[70000];
    unsigned int i, j;
    unsigned int steps = 1;
    int is_prime = 1;
    int prime_cnt = 2;

    for(i = 5; i < 100000; i += 2)
    {
        is_prime = 1;
        for(j = 2; j * j <= i; j++)
        {
            steps++;
            if(i % j == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if(is_prime)
        {
            prime_cnt++;
            printf("%u\n", i);
        }
    }
    printf("steps = %d prime_cnt = %d\n", steps, prime_cnt);
}
/*steps = 694438 prime_cnt = 9592*/
void make_primes2()
{
    unsigned int max_num = -1;
    unsigned int primes[70000];
    unsigned int i, j;
    unsigned int steps = 1;
    int is_prime = 1;
    int prime_cnt = 2;

    primes[0] = 2;
    primes[1] = 3;

    for(i = 5; i < 100000; i += 2)
    {
        is_prime = 1;
        for(j = 0; primes[j] * primes[j] <= i; j++)
        {
            steps++;
            if(i % primes[j] == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if(is_prime)
        {
            primes[prime_cnt++] = i;

            printf("%u\n", i);
        }
    }
    printf("steps = %d prime_cnt = %d\n", steps, prime_cnt);
}
/*ɸѡ����������steps = 252155 prime_cnt = 9593*/
void make_primes3()
{
    unsigned int max_num = 100000;
    short primes[100000] = {0};
    unsigned int i, j;
    unsigned int steps = 1;
    int prime_cnt = 1;

    for(i = 1; i < max_num; i += 2)
    {
        primes[i] = 1;
        //steps++;
    }

    for(i = 3; i * i < max_num; i += 2)
    {
        if(primes[i])
        {
            for(j = i + i; j < max_num; j += i)
            {
                primes[j] = 0;
                steps++;
            }
        }
    }

    for(i = 1; i < max_num; i += 2)
    {
        if(primes[i])
        {
            prime_cnt++;
        }
        //steps++;
    }
    printf("steps = %d prime_cnt = %d\n", steps, prime_cnt);
}

/*ʲô���������Ĳ������С�ַ��������ĸ�ڴ��ַ����ﶼ�У�
���磬��������������ַ�����
String 1: ABCDEFGHLMNOPQRS
String 2: DCGSRQPOM
���� true�������� string2 �����ĸ string1 Ҳ���С�*/
int is_sub_str(char *main_str, char *sub_str, int main_str_cnt, int sub_str_cnt)
{
    unsigned int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
        59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    unsigned int result = 1;
    short flags[26] = {0};
    int index;
    int i;

    for(i = 0; i < main_str_cnt; i++)
    {
        index = main_str[i] - 'a';
        if(flags[index] == 0)
        {
            flags[index] = 1;
            //result *= primes[index];
        }
    }

    for(i = 0; i < sub_str_cnt; i++)
    {
        index = sub_str[i] - 'a';
        if(flags[index] == 0)
        {
            break;
        }
    }

    if(i == sub_str_cnt)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*��һ���ַ������ҵ���һ��ֻ��
��һ�ε��ַ��������� abaccdeff������� b��*/
void find_first_char(const char *str, int str_len)
{
    int char_map[256] = {0};
    int i;

    i = 0;
    while(i < str_len)
    {
        char_map[str[i]]++;
        i++;
    }

    i = 0;
    while(i < str_len)
    {
        if(char_map[str[i]] == 1)
        {
            printf("%c\n", str[i]);
            return;
        }
        i++;
    }
    printf("Not found!\n");
    return;
}

/*����һ����ʾ�������ַ������Ѹ��ַ���ת���������������
���������ַ���"345"����������� 345��*/
int char_to_int(const char *str, int str_len)
{
    int i;
    int symb = 1;
    int result = 0;

    /*����Ҫ���ĵ�һ�����ж����ָ���ǲ���Ϊ�ա�*/
    if(NULL == str)
    {
        return -1;
    }

    i = 0;
    /*�������ܲ�����֮�������֣����п�����'+'����'-'��ͷ*/
    if(str[i] == '+')
    {
        symb = 1;
        i++;
    }
    else if(str[i] == '-')
    {
        symb = -1;
        i++;
    }

    for(; i < str_len; i++)
    {
        /*������ַ����п��ܺ��в������ֵ��ַ���
        ÿ��������Щ�Ƿ����ַ������Ǿ�û�б�Ҫ��
        ����ת����*/
        if(str[i] < '0' || str[i] > '9')
        {
            printf("Illegal character!\n");
            return -1;
        }

        result = result * 10 + (str[i] - '0');

        /*�������*/
        if(result < 0)
        {
            printf("Overflow!\n");
            return -1;
        }
    }
    result *= symb;
    printf("Converted number = %d\n", result);
    return 1;
}
int main()
{
    char main_str[50] = "voieanbohawebsvfqqisofnuyhinteqtirojovnmbiw";
    char sub_str[20] = "aebxsvf";
    char number[10] = "35375682";
    int main_str_cnt, sub_str_cnt;
    int i;

    main_str_cnt = strlen(main_str);
    sub_str_cnt = strlen(sub_str);

    i = is_sub_str(main_str, sub_str, main_str_cnt, sub_str_cnt);
    find_first_char(main_str, main_str_cnt);
    char_to_int(number, 8);
    printf("%d\n", i);
    printf("Hello world!\n");
    return 0;
}
