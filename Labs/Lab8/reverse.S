	.intel_syntax noprefix
	.text
	.global reverse_asm

         reverse_asm:
             push ebx
               #Now, we can use ebx for headptr, ecx for nextptr, and edxfor newhead_ptr.
               #reversal code goes here
             
             #headptr = nextptr = new_headptr = NULL
             #we use eax as the scratch register
             mov eax, 0x0
             mov ebx, eax
             mov ecx, eax
             mov edx, eax

            # equivalent to if (head == NULL) return NULL;
             mov eax, [esp + 8]
             cmp eax, 0
             je null_ret
     
           #more code comes here
  
            

         # HEADPTR = EBX, NEXTPTR = ECX,  NEWHEADPTR = EDX
             

           #headptr = &(head->ptr)
           add eax, [esp + 12]
           #ebx is headptr
           mov ebx, eax

           while_start:
              #while (headptr)
              cmp ebx, 0x0
               je while_done

              #nextptr = (void*) (*((unsigned long*)headptr));
              mov ecx, [ebx]

              # *(unsigned long *) headptr = (unsigned long) new_headptr;
              mov [ebx], edx

              #new_headptr = headptr
               mov edx, ebx

              #headptr = nextptr
               mov ebx, ecx
 
              # next iteration
               jmp while_start

           while_done:
             #CODE THAT FOLLOWS WHILE LOOP *** 
             mov eax,edx
             sub eax, [esp + 12]


         null_ret:
                 pop ebx
                 ret


           pop ebx
             ret

