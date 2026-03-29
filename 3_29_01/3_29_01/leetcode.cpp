int firstUniqChar(char* s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        char tmp = s[i];
        int flag = 1;
        for (int j = 0; j < strlen(s); j++)
        {
            if (j == i)
            {
                continue;
            }
            if (tmp == s[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    return 0;
}