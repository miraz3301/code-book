ll root=sqrtl((long double)n);
while((__int128)(root+1)*(root+1)<=n)root++;
while((__int128)root*root>n)root--;
