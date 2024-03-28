#include <stdio.h>
#include <math.h>



int  main(void){

  
    char z;
    double e, b, i, c, d, n, m, f, r,s,v,g,i,h,k,l,w;
    s = pow(10, -12);   //potenze 
    v = pow(10, 7);     //potenze
    b = 500 * s;        //T(setup)
    c = 200 * s;        //tau
    d = 0.2;           //(N) 
    n = 150 * s;       //T(0)
    m = 3.1415926535897 *v *v;  //pi
    f = m * d * n;     
    h=pow(10,-9);
    w= pow(10, 9);
    /*i=3.036*h; 
     

    r = (i - b)/ c; // r==12.6
    e = pow(2.718281828459, r); //e==321258.058596
    g=((i*e)/(d*n))*v;
    l=g/m;

    z=(char)l;

    printf("%f\n", r);

    //  printf("%d",z);

    /* for (double i = 2.90; i < 3.20; i+=0.01)
    {
        
       r = (i - b) / c;            // r==12.5
       e = pow(2.718281828459, r); //e==268337.28
       g = ((i * e) / (d * n)) * v;
       l = g / m;
       z = (char)l;
       if (i==2.91)
       {
           puts("ciao");
       }
       

       if (z==1)
       {
           printf("Il valore e': %f",i); 
           break;
       }
       
    }*/

    for ( i = 0.00; i < 10.00; i += 0.01)
    {
        r = (i*h - b) / c;
        e = pow(2.718281828459, r);
        g = ((i * e) / (d * n)) * v;
        l = g / (m*w);
        z = (char)l;       
        if (z == 1)
        {
            printf("Il valore e': %.3f ns", i);
            break;
        }
    }

    double MTBF = 1/i;
    
  

    //printf("%f",g/k);

    /* for (float i = 0.00000000001; i < 3.0000050001; i += 0.00000000001)
    {
        if (i==0.000000002)
        {
            printf("sei arrivato a 0.02\n");
            break;
        }
        
        r = (i - b) / c;
        e = pow(2.7, r);

        if ((i * e) == f)
        {
            printf("Il risultato e': %.2f\n",i);
            break;
        }
        if (i==2.00)
        {
            printf("sei arrivato a 2\n");
        }
        if (i==4.00)   
        {
            printf("sei arrivato a 4\n");
        } 
        if (i==6.00)
        {
           printf("sei arrivato a 6\n");
        }
        if (i==8.00)
        {          
            printf("sei arrivato a 8\n");
        }
        if (i==10.00)
        {
            printf("sei arrivato a 10\n");
        }
    }*/
}