        long double ax,ay,bx,by,cx,cy;
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        long double x=cy-by;
        long double y=bx-cx;
        long double c=-(bx-cx)*by+(by-cy)*bx;
        long double dis=abs(x*ax+y*ay+c)/sqrt(x*x+y*y);
        cout<<fixed<<setprecision(10)<<dis;
