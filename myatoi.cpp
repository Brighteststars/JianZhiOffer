int MyAtoi(string str)
{
    if(str.size() == 0)
        return 0;
    long retNum = 0;
    int i = 0, sign = 1;
    while(str[i] == ' ')
        i++;        //skip white
    if(i >= (int)str.size())
        return 0;


    if(str[i] == '+' || str[i] == '-' || isdigit(str[i]))
    {
        if(!isdigit(str[i]))
            sign = str[i++] == '+' ? 1 : -1;
        while(i < (int)str.size() && isdigit(str[i]))
        {
            retNum = retNum*10 + str[i++] - '0';
            if(retNum > INT_MAX)
                return sign > 0 ? INT_MAX : INT_MIN;
        }

    }else
        return 0;

    return (int)retNum * sign;


}

void main()
{

    cout << MyAtoi(" +123 ");


    return;
}
