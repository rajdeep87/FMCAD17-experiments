int main()
{
  int x=9;
  x=((x>>3)<<3)|4;
  assert(x==12);
  int y=8;
  y=y&0xE|1<<0;
  assert(y==9);
  int z=5;
  z=z|0x02<<3;
  assert(z==0x15);
  int c=0;
  c=0x00000002<<30;
  assert(c==2^31-1);
}
