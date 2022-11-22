global main
extern printf, scanf

section .text

main: 

  ;Starting of code
  push rbp
  mov rbp, rsp
  sub rsp, 16

  ;Taking Integer Input
  mov eax, 0
  lea rdi, [numInput]
  call printf

  mov eax, 0
  lea rdi, [numFormat]
  lea rsi, [number]
  call scanf

  ;Taking String Input
  xor eax, eax
  lea rdi, [stringInput]
  call printf

  lea rdi, [stringFormat]
  lea rsi, [line]
  call scanf

  ;Printing Integer Output
  mov eax, 0
  lea rdi, [numOutput]
  call printf

  mov eax, 0
  lea rdi, [numFormat]
  mov rsi, [number]
  call printf

  ;Printing new Line
  mov eax, 0
  lea rdi, [newLineCreater]
  call printf

  ;Printing String output
  mov eax, 0
  lea rdi, [stringOutput]
  call printf

  mov eax, 0
  lea rdi, [stringFormat]
  lea rsi, [line]
  call printf

  ;Adding new Line
  mov eax, 0
  lea rdi, [newLineCreater]
  call printf

  ;Closing
  add rsp, 16
  leave
  ret

section .data
  numInput db "Enter a number: "          ,0
  numFormat db "%d"                       ,0
  numOutput db "Your Entered Number: "    ,0

  stringInput db "Enter a string: "       ,0
  stringFormat db "%s"                    ,0
  stringOutput db "Your Entered String: " ,0

  newLineCreater db 10,0

section .bss
  number resb 4
  line resb 100