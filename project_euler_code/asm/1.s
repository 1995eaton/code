.intel_syntax noprefix
.include "extra.s"

.globl f
f:
  xor edx, edx
  mov rax, 999
  div rdi
  mov rcx, rax
  inc rcx
  mul rcx
  shr rax, 1
  mul rdi
  ret

.globl pu1
pu1:
  mov rdi, 3
  call f
  mov r8, rax
  mov rdi, 5
  call f
  add r8, rax
  mov rdi, 15
  call f
  sub r8, rax
  mov rax, r8
  ret

.globl _start
_start:
  mov rdi, 999
  call pu1

  mov rdi, rax
  call putq

  mov rax, 60
  xor edi, edi
  syscall
