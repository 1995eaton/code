.intel_syntax noprefix

.text

.globl strlen; strlen:
  xor rax, rax
  cmpb [rdi], 0
  je 1f
  0:
    add rax, 1
    cmpb [rdi + rax], 0
    jne 0b
  1:
  ret

.globl prints; prints:
  push rdi
  call strlen
  pop rsi
  mov rdx, rax
  mov rax, 1
  mov rdi, 1
  syscall
  ret

.globl putchar; putchar:
  movb [rsp - 1], dil
  mov rax, 1
  mov rdi, 1
  lea rsi, [rsp - 1]
  mov rdx, 1
  syscall
  ret

.globl puts; puts:
  call prints
  mov dil, '\n'
  call putchar
  ret

.globl putq; putq:
  sub rsp, 32
  mov rsi, rsp
  call q2str
  mov rdi, rsp
  call puts
  add rsp, 32
  ret

.globl putsq; putsq:
  sub rsp, 32
  mov rsi, rsp
  call sq2str
  mov rdi, rsp
  call puts
  add rsp, 32
  ret

.globl q2str; q2str:
  push rbp
  mov rbp, rsp
  sub rsp, 32
  movb [rbp - 1], 0
  mov rax, rdi
  mov rdi, rsi
  lea rsi, [rbp - 1]
  mov rcx, 10
  0:
    sub rsi, 1
    xor rdx, rdx
    div rcx
    add dl, 48
    mov [rsi], dl
    test rax, rax
    jne 0b
  mov rcx, rbp
  sub rcx, rsi
  rep movsb
  leave
  ret

.globl sq2str; sq2str:
  test rdi, rdi
  jns 0f
    movb [rsi], '-'
    add rsi, 1
    neg rdi
  0:
  call q2str
  ret
