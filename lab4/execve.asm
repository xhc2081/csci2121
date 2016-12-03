.section .text
   .globl _start
  _start:

   push 0x0000
   push $0x68732f2f
   push $0x6e69622f
   mov  %esp,%ebx
   
   push 0x0000
   push %ebx
   mov  %esp,%ecx

   mov  $0xb,%eax
   mov  $0x0,%edx
   
   int  $0x80
