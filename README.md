<h1>Branch names link to some dummy projects just for learning C</h1> 

<h2>Here there are some tips</h2>

<h3>Formatting letter in printf</h3>
    <ul>
        <li>int -> d</li>
        <li>float -> .(number of digits) f uo to 6-7 digits</li>
        <li>float -> .(number of digits) lf uo to 15-16 digits</li>
        <li>char as letter -> c</li>
        <li>char[] as string -> s</li>
        <li>bool -> d</li>
        <li>char as number (-128 +127) -> c or d</li>
        <li>short int -> d</li>
        <li>unsigned short int -> d</li>
        <li>unsigned int -> u</li>
        <li>long long int -> lld</li>
        <li>unsigned long long int -> llu</li>
        <li>double -> lf</li>
        <li>min field width -> %(num)</li>
        <li>left alling -> %-</li>
        <li>*p for printing a pointer value</li>
    </ul>

<h3>Pointers</h3>
    <ul>
        <li>int *p -> pointer</li>
        <li>*p = 5 -> assigning a value to the pointer</li>
        <li>p = &a -> assigning a memery reference to the pointer</li>
        <li>very useful for strings (char array)</li>
        <li>very useful for strings (char array)</li>
        <li>very useful for modifing values using a custome function in loops, otherwise values are passed by value copy and not by memory reference, see BubleSort.c</li>
        <li>const char *b -> a pointer that points to a const, so it can point to every char but it cannot modify them</li>
        <li>const char * const b -> a const pointer that points to a const, so it'a a read-only object, you can change neither what pointer points or the value to whom it is pointing</li>
        <li>int * compare(int,int) -> function that returs a pointer to int</li>
        <li>int (*compare)(int,int) -> compare is a pointer to a function</li>
        <li>an array of string is just an array of pointers, where each pointer points to the first char of each string
        so char *cars={"Ferrari","Lamborghini"} is the same as char cars[2][25]={"Ferrari","Lamborghini"}</li>
        <li>int (*compare)(int,int) -> compare is a pointer to a function</li>  
    </ul>

<h3>Strings manipulation</h3>
    <ul>
        <li>strcmp e strncmp return 0 if the first string is equal to the second one, -1 if is shorter, 1 if is longer</li>
        <li>you can directly manipulate bytes using memcpy,memmove,memcp,memchr,memset</li>
    </ul>

<h3>Other stuff</h3>
    <ul>
        <li>Strange behivour using arrays, see "ArraysInt.c" for further evidence</li>
        <li>char char is a single character</li>
        <li>char string[] is a string</li>
        <li>char string[n][m] is an array of n string containing max m characther each</li>
        <li>I wrote a strange algorithm for sorting in "BubleSort.c" i don't get why it works</li>
    </ul>

