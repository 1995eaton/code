.intel_syntax noprefix
.include "./extra.s"

pu3:
  push rbp
  mov rbp, rsp
  sub rsp, 24

  mov [rbp - 8], rdi # n
  movq [rbp - 16], 2 # i
  movq [rbp - 24], 1 # largest factor

  jmp 0f
  1:
    mov rax, [rbp - 8]
    mov rcx, [rbp - 16]
    xor edx, edx
    div rcx
    test rdx, rdx
    jnz 2f
    mov [rbp - 8], rax
    mov [rbp - 24], rcx
    jmp 1b
  2:
    incq [rbp - 16]
  0:
    cmpq [rbp - 8], 1
    jne 1b

  mov rax, [rbp - 24]

  mov rsp, rbp
  pop rbp
  ret

.globl _start
_start:
  mov rdi, 600851475143
  call pu3

  mov rdi, rax
  call putq

  mov eax, 60
  xor edi, edi
  syscall
