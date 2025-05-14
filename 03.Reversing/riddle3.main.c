#include <stdio.h>

int __cdecl main(int argc, const char **argv, const char **envp)
{
  int a;  // [esp+0h] [ebp-Ch]
  int b;  // [esp+4h] [ebp-8h] BYREF

  scanf("%d", &b);

  a = collatz_conjecture(b);

  printf("Num %d took total %d iterations\n", b, a);

  return 0;
}

/// Count the number of iterations until the number reaches 1
/// according to the Collatz conjecture.
int __cdecl collatz_conjecture(int a1)
{
  int v2; // [esp+0h] [ebp-4h]

  v2 = 0;
  while ( a1 != 1 )
  {
    if ( a1 % 2 )
      a1 = 3 * a1 + 1;
    else
      a1 /= 2;
    printf("%d iteration: %d\n", ++v2, a1);
  }
  return v2;
}