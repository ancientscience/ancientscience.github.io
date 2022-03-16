auto iterate(int len) 
{
  for (int i = 0; i < len; ++i)
    if (i == 10)
      return i;
  return -1;
}

int main()
{
    iterate(15);
}
