section .data
    hello db "Hello, Holberton", 0
    format db "%s", 0
    newline db 10, 0

section .text
    global main

extern printf

main:
    sub rsp, 8               ; Align stack (16-byte alignment)
    mov rdi, format
    mov rsi, hello
    call printf

    mov rdi, format
    mov rsi, newline
    call printf

    add rsp, 8               ; Restore original stack pointer
    mov rax, 60             ; syscall: exit
    xor rdi, rdi             ; status: 0
    syscall

