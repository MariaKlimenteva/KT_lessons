int sendall(int s, char *buf, int len, int flags)
{
    int total = 0;
    int n;

    while(total < len)
    {
        n = send(s, buf+total, len-total, flags);
        if(n == -1) {break; }
        total += n;
    }

    return (n == -1 ? -1 : total);
}