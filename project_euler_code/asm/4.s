.intel_syntax noprefix
.include "./extra.s"

is_palindrone:
  push rbp
  mov rbp, rsp
  sub rsp, 24

  mov [rbp - 8], rdi   # n_orig
  movq [rbp - 16], rdi # n
  movq [rbp - 24], 0   # n_rev

  mov ecx, 10

  0:
    mov rax, [rbp - 24]
    mul rcx
    mov [rbp - 24], rax

    xor edx, edx
    mov rax, [rbp - 16]
    div rcx
    add [rbp - 24], rdx
    mov [rbp - 16], rax

    cmpq [rbp - 16], 0
    jne 0b

  mov rax, [rbp - 8]
  cmp [rbp - 24], rax
  sete al

  mov rsp, rbp
  pop rbp
  ret

pu4:
  push rbp
  mov rbp, rsp
  sub rsp, 64

  mov [rbp - 8], rdi  # start
  mov [rbp - 16], rsi # end
  movq [rbp - 24], 0  # max
  mov [rbp - 32], rsi # a
  movq [rbp - 40], 0  # b

  jmp 0f
  1:
    mov rax, [rbp - 16]
    mov [rbp - 40], rax

    mov rax, [rbp - 32]
    mulq [rbp - 16]
    cmp rax, [rbp - 24]
    jl end

    jmp 2f
  3:

    mov rax, [rbp - 32]
    mulq [rbp - 40]

    mov [rbp - 48], rax # prod
    cmpq rax, [rbp - 24]
    jl 4f

    mov rdi, [rbp - 48]
    call is_palindrone
    test al, al
    jz 5f
    mov rax, [rbp - 48]
    mov [rbp - 24], rax
  5:
    decq [rbp - 40]
  2:
    mov rax, [rbp - 40]
    cmp rax, [rbp - 32]
    jge 3b

  4:
    decq [rbp - 32]
  0:
    mov rax, [rbp - 32]
    cmp rax, [rbp - 8]
    jge 1b
  end:

  mov rax, [rbp - 24]

  mov rsp, rbp
  pop rbp
  ret

.globl _start
_start:
  mov rdi, 100
  mov rsi, 999
  call pu4

  mov rdi, rax
  call putq

  mov eax, 60
  xor edi, edi
  syscall
