.intel_syntax noprefix
.include "extra.s"

pu2:
  mov rax, 0
  mov rcx, 1
  xor edx, edx

  jmp 0f
  1:
    test rax, 1
    jnz 0f
    add rdx, rax
  0:
    xadd rax, rcx
    cmp rax, 4000000
    jbe 1b

  mov rax, rdx
  ret

.globl _start
_start:
  call pu2
  mov rdi, rax
  call putq

  mov eax, 60
  xor edi, edi
  syscall
