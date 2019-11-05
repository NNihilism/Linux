使用valgrind工具跟踪几种错误

============================================================================

nnihilism@nnihilism-virtual-machine:~/桌面/Linux/Project9/exam4$ valgrind --track-fds=yes --leak-check=full --undef-value-errors=yes ./memtest
==7430== Memcheck, a memory error detector
==7430== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==7430== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==7430== Command: ./memtest
==7430== 
==7430== Invalid write of size 2
==7430==    at 0x400677: mem_overrun1 (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==    by 0x400723: main (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==  Address 0x5204300 is 0 bytes inside a block of size 1 alloc'd
==7430==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7430==    by 0x40066E: mem_overrun1 (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==    by 0x400723: main (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430== 
==7430== Invalid free() / delete / delete[] / realloc()
==7430==    at 0x4C2EDEB: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7430==    by 0x4006F6: mem_double_free (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==    by 0x40072D: main (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==  Address 0x5204350 is 0 bytes inside a block of size 1 free'd
==7430==    at 0x4C2EDEB: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7430==    by 0x4006EA: mem_double_free (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==    by 0x40072D: main (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==  Block was alloc'd at
==7430==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7430==    by 0x4006DA: mem_double_free (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==    by 0x40072D: main (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430== 
==7430== Conditional jump or move depends on uninitialised value(s)
==7430==    at 0x4C2EDA1: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7430==    by 0x40070D: mem_free_wild_pointer (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==    by 0x400732: main (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430== 
==7430== Invalid free() / delete / delete[] / realloc()
==7430==    at 0x4C2EDEB: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7430==    by 0x40070D: mem_free_wild_pointer (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==    by 0x400732: main (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==  Address 0x5204350 is 0 bytes inside a block of size 1 free'd
==7430==    at 0x4C2EDEB: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7430==    by 0x4006EA: mem_double_free (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==    by 0x40072D: main (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==  Block was alloc'd at
==7430==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7430==    by 0x4006DA: mem_double_free (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==    by 0x40072D: main (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430== 
==7430== 
==7430== FILE DESCRIPTORS: 4 open at exit.
==7430== Open file descriptor 3: test.txt
==7430==    at 0x4F31040: __open_nocancel (syscall-template.S:84)
==7430==    by 0x4EB3ACD: _IO_file_open (fileops.c:221)
==7430==    by 0x4EB3D34: _IO_file_fopen@@GLIBC_2.2.5 (fileops.c:328)
==7430==    by 0x4EA7D33: __fopen_internal (iofopen.c:86)
==7430==    by 0x400655: mem_leak2 (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==    by 0x40071E: main (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430== 
==7430== Open file descriptor 2: /dev/pts/19
==7430==    <inherited from parent>
==7430== 
==7430== Open file descriptor 1: /dev/pts/19
==7430==    <inherited from parent>
==7430== 
==7430== Open file descriptor 0: /dev/pts/19
==7430==    <inherited from parent>
==7430== 
==7430== 
==7430== HEAP SUMMARY:
==7430==     in use at exit: 553 bytes in 2 blocks
==7430==   total heap usage: 4 allocs, 4 frees, 555 bytes allocated
==7430== 
==7430== 1 bytes in 1 blocks are definitely lost in loss record 1 of 2
==7430==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7430==    by 0x400637: mem_leak1 (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430==    by 0x400719: main (in /home/nnihilism/桌面/Linux/Project9/exam4/memtest)
==7430== 
==7430== LEAK SUMMARY:
==7430==    definitely lost: 1 bytes in 1 blocks
==7430==    indirectly lost: 0 bytes in 0 blocks
==7430==      possibly lost: 0 bytes in 0 blocks
==7430==    still reachable: 552 bytes in 1 blocks
==7430==         suppressed: 0 bytes in 0 blocks
==7430== Reachable blocks (those to which a pointer was found) are not shown.
==7430== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==7430== 
==7430== For counts of detected and suppressed errors, rerun with: -v
==7430== Use --track-origins=yes to see where uninitialised values come from
==7430== ERROR SUMMARY: 6 errors from 5 contexts (suppressed: 0 from 0)

