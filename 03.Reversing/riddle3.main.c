#include <stdio.h>

int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v4;  // [esp+0h] [ebp-Ch]
  int v5;  // [esp+4h] [ebp-8h] BYREF

  scanf("%d", v5);
  v4 = user_defined(*(int *)v5);
  printf("Num %d took total %d iterations\n", v5, v4);
  return 0;
}

int __cdecl user_defined(int a1)
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