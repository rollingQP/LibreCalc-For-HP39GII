// Supported modes
#define SWIL_MODE_LINUX 0
#define SWI_MODE_ARMEABI 1

// Select one mode from above
#define SWI_MODE SWI_MODE_ARMEABI 

#if SWI_MODE == SWI_MODE_LINUX

#define SWI_READ 0
#define SWI_WRITE 1
#define SWI_OPEN 2
#define SWI_CLOSE 3
#define SWI_STAT 4
#define SWI_FSTAT 5
#define SWI_LSTAT 6
#define SWI_POLL 7
#define SWI_LSEEK 8
#define SWI_MMAP 9
#define SWI_MPROTECT 10
#define SWI_MUNMAP 11
#define SWI_BRK 12
#define SWI_RT_SIGACTION 13
#define SWI_RT_SIGPROCMASK 14
#define SWI_RT_SIGRETURN 15
#define SWI_IOCTL 16
#define SWI_PREAD64 17
#define SWI_PWRITE64 18
#define SWI_READV 19
#define SWI_WRITEV 20
#define SWI_ACCESS 21
#define SWI_PIPE 22
#define SWI_SELECT 23
#define SWI_SCHED_YIELD 24
#define SWI_MREMAP 25
#define SWI_MSYNC 26
#define SWI_MINCORE 27
#define SWI_MADVISE 28
#define SWI_SHMGET 29
#define SWI_SHMAT 30
#define SWI_SHMCTL 31
#define SWI_DUP 32
#define SWI_DUP2 33
#define SWI_PAUSE 34
#define SWI_NANOSLEEP 35
#define SWI_GETITIMER 36
#define SWI_ALARM 37
#define SWI_SETITIMER 38
#define SWI_GETPID 39
#define SWI_SENDFILE 40
#define SWI_SOCKET 41
#define SWI_CONNECT 42
#define SWI_ACCEPT 43
#define SWI_SENDTO 44
#define SWI_RECVFROM 45
#define SWI_SENDMSG 46
#define SWI_RECVMSG 47
#define SWI_SHUTDOWN 48
#define SWI_BIND 49
#define SWI_LISTEN 50
#define SWI_GETSOCKNAME 51
#define SWI_GETPEERNAME 52
#define SWI_SOCKETPAIR 53
#define SWI_SETSOCKOPT 54
#define SWI_GETSOCKOPT 55
#define SWI_CLONE 56
#define SWI_FORK 57
#define SWI_VFORK 58
#define SWI_EXECVE 59
#define SWI_EXIT 60
#define SWI_WAIT4 61
#define SWI_KILL 62
#define SWI_UNAME 63
#define SWI_SEMGET 64
#define SWI_SEMOP 65
#define SWI_SEMCTL 66
#define SWI_SHMDT 67
#define SWI_MSGGET 68
#define SWI_MSGSND 69
#define SWI_MSGRCV 70
#define SWI_MSGCTL 71
#define SWI_FCNTL 72
#define SWI_FLOCK 73
#define SWI_FSYNC 74
#define SWI_FDATASYNC 75
#define SWI_TRUNCATE 76
#define SWI_FTRUNCATE 77
#define SWI_GETDENTS 78
#define SWI_GETCWD 79
#define SWI_CHDIR 80
#define SWI_FCHDIR 81
#define SWI_RENAME 82
#define SWI_MKDIR 83
#define SWI_RMDIR 84
#define SWI_CREAT 85
#define SWI_LINK 86
#define SWI_UNLINK 87
#define SWI_SYMLINK 88
#define SWI_READLINK 89
#define SWI_CHMOD 90
#define SWI_FCHMOD 91
#define SWI_CHOWN 92
#define SWI_FCHOWN 93
#define SWI_LCHOWN 94
#define SWI_UMASK 95
#define SWI_GETTIMEOFDAY 96
#define SWI_GETRLIMIT 97
#define SWI_GETRUSAGE 98
#define SWI_SYSINFO 99
#define SWI_TIMES 100
#define SWI_PTRACE 101
#define SWI_GETUID 102
#define SWI_SYSLOG 103
#define SWI_GETGID 104
#define SWI_SETUID 105
#define SWI_SETGID 106
#define SWI_GETEUID 107
#define SWI_GETEGID 108
#define SWI_SETPGID 109
#define SWI_GETPPID 110
#define SWI_GETPGRP 111
#define SWI_SETSID 112
#define SWI_SETREUID 113
#define SWI_SETREGID 114
#define SWI_GETGROUPS 115
#define SWI_SETGROUPS 116
#define SWI_SETRESUID 117
#define SWI_GETRESUID 118
#define SWI_SETRESGID 119
#define SWI_GETRESGID 120
#define SWI_GETPGID 121
#define SWI_SETFSUID 122
#define SWI_SETFSGID 123
#define SWI_GETSID 124
#define SWI_CAPGET 125
#define SWI_CAPSET 126
#define SWI_RT_SIGPENDING 127
#define SWI_RT_SIGTIMEDWAIT 128
#define SWI_RT_SIGQUEUEINFO 129
#define SWI_RT_SIGSUSPEND 130
#define SWI_SIGALTSTACK 131
#define SWI_UTIME 132
#define SWI_MKNOD 133
#define SWI_USELIB 134
#define SWI_PERSONALITY 135
#define SWI_USTAT 136
#define SWI_STATFS 137
#define SWI_FSTATFS 138
#define SWI_SYSFS 139
#define SWI_GETPRIORITY 140
#define SWI_SETPRIORITY 141
#define SWI_SCHED_SETPARAM 142
#define SWI_SCHED_GETPARAM 143
#define SWI_SCHED_SETSCHEDULER 144
#define SWI_SCHED_GETSCHEDULER 145
#define SWI_SCHED_GET_PRIORITY_MAX 146
#define SWI_SCHED_GET_PRIORITY_MIN 147
#define SWI_SCHED_RR_GET_INTERVAL 148
#define SWI_MLOCK 149
#define SWI_MUNLOCK 150
#define SWI_MLOCKALL 151
#define SWI_MUNLOCKALL 152
#define SWI_VHANGUP 153
#define SWI_MODIFY_LDT 154
#define SWI_PIVOT_ROOT 155
#define SWI__SYSCTL 156
#define SWI_PRCTL 157
#define SWI_ARCH_PRCTL 158
#define SWI_ADJTIMEX 159
#define SWI_SETRLIMIT 160
#define SWI_CHROOT 161
#define SWI_SYNC 162
#define SWI_ACCT 163
#define SWI_SETTIMEOFDAY 164
#define SWI_MOUNT 165
#define SWI_UMOUNT2 166
#define SWI_SWAPON 167
#define SWI_SWAPOFF 168
#define SWI_REBOOT 169
#define SWI_SETHOSTNAME 170
#define SWI_SETDOMAINNAME 171
#define SWI_IOPL 172
#define SWI_IOPERM 173
#define SWI_CREATE_MODULE 174
#define SWI_INIT_MODULE 175
#define SWI_DELETE_MODULE 176
#define SWI_GET_KERNEL_SYMS 177
#define SWI_QUERY_MODULE 178
#define SWI_QUOTACTL 179
#define SWI_NFSSERVCTL 180
#define SWI_GETPMSG 181
#define SWI_PUTPMSG 182
#define SWI_AFS_SYSCALL 183
#define SWI_TUXCALL 184
#define SWI_SECURITY 185
#define SWI_GETTID 186
#define SWI_READAHEAD 187
#define SWI_SETXATTR 188
#define SWI_LSETXATTR 189
#define SWI_FSETXATTR 190
#define SWI_GETXATTR 191
#define SWI_LGETXATTR 192
#define SWI_FGETXATTR 193
#define SWI_LISTXATTR 194
#define SWI_LLISTXATTR 195
#define SWI_FLISTXATTR 196
#define SWI_REMOVEXATTR 197
#define SWI_LREMOVEXATTR 198
#define SWI_FREMOVEXATTR 199
#define SWI_TKILL 200
#define SWI_TIME 201
#define SWI_FUTEX 202
#define SWI_SCHED_SETAFFINITY 203
#define SWI_SCHED_GETAFFINITY 204
#define SWI_SET_THREAD_AREA 205
#define SWI_IO_SETUP 206
#define SWI_IO_DESTROY 207
#define SWI_IO_GETEVENTS 208
#define SWI_IO_SUBMIT 209
#define SWI_IO_CANCEL 210
#define SWI_GET_THREAD_AREA 211
#define SWI_LOOKUP_DCOOKIE 212
#define SWI_EPOLL_CREATE 213
#define SWI_EPOLL_CTL_OLD 214
#define SWI_EPOLL_WAIT_OLD 215
#define SWI_REMAP_FILE_PAGES 216
#define SWI_GETDENTS64 217
#define SWI_SET_TID_ADDRESS 218
#define SWI_RESTART_SYSCALL 219
#define SWI_SEMTIMEDOP 220
#define SWI_FADVISE64 221
#define SWI_TIMER_CREATE 222
#define SWI_TIMER_SETTIME 223
#define SWI_TIMER_GETTIME 224
#define SWI_TIMER_GETOVERRUN 225
#define SWI_TIMER_DELETE 226
#define SWI_CLOCK_SETTIME 227
#define SWI_CLOCK_GETTIME 228
#define SWI_CLOCK_GETRES 229
#define SWI_CLOCK_NANOSLEEP 230
#define SWI_EXIT_GROUP 231
#define SWI_EPOLL_WAIT 232
#define SWI_EPOLL_CTL 233
#define SWI_TGKILL 234
#define SWI_UTIMES 235
#define SWI_VSERVER 236
#define SWI_MBIND 237
#define SWI_SET_MEMPOLICY 238
#define SWI_GET_MEMPOLICY 239
#define SWI_MQ_OPEN 240
#define SWI_MQ_UNLINK 241
#define SWI_MQ_TIMEDSEND 242
#define SWI_MQ_TIMEDRECEIVE 243
#define SWI_MQ_NOTIFY 244
#define SWI_MQ_GETSETATTR 245
#define SWI_KEXEC_LOAD 246
#define SWI_WAITID 247
#define SWI_ADD_KEY 248
#define SWI_REQUEST_KEY 249
#define SWI_KEYCTL 250
#define SWI_IOPRIO_SET 251
#define SWI_IOPRIO_GET 252
#define SWI_INOTIFY_INIT 253
#define SWI_INOTIFY_ADD_WATCH 254
#define SWI_INOTIFY_RM_WATCH 255
#define SWI_MIGRATE_PAGES 256
#define SWI_OPENAT 257
#define SWI_MKDIRAT 258
#define SWI_MKNODAT 259
#define SWI_FCHOWNAT 260
#define SWI_FUTIMESAT 261
#define SWI_NEWFSTATAT 262
#define SWI_UNLINKAT 263
#define SWI_RENAMEAT 264
#define SWI_LINKAT 265
#define SWI_SYMLINKAT 266
#define SWI_READLINKAT 267
#define SWI_FCHMODAT 268
#define SWI_FACCESSAT 269
#define SWI_PSELECT6 270
#define SWI_PPOLL 271
#define SWI_UNSHARE 272
#define SWI_SET_ROBUST_LIST 273
#define SWI_GET_ROBUST_LIST 274
#define SWI_SPLICE 275
#define SWI_TEE 276
#define SWI_SYNC_FILE_RANGE 277
#define SWI_VMSPLICE 278
#define SWI_MOVE_PAGES 279
#define SWI_UTIMENSAT 280
#define SWI_EPOLL_PWAIT 281
#define SWI_SIGNALFD 282
#define SWI_TIMERFD_CREATE 283
#define SWI_EVENTFD 284
#define SWI_FALLOCATE 285
#define SWI_TIMERFD_SETTIME 286
#define SWI_TIMERFD_GETTIME 287
#define SWI_ACCEPT4 288
#define SWI_SIGNALFD4 289
#define SWI_EVENTFD2 290
#define SWI_EPOLL_CREATE1 291
#define SWI_DUP3 292
#define SWI_PIPE2 293
#define SWI_INOTIFY_INIT1 294
#define SWI_PREADV 295
#define SWI_PWRITEV 296
#define SWI_RT_TGSIGQUEUEINFO 297
#define SWI_PERF_EVENT_OPEN 298
#define SWI_RECVMMSG 299
#define SWI_FANOTIFY_INIT 300
#define SWI_FANOTIFY_MARK 301
#define SWI_PRLIMIT64 302
#define SWI_NAME_TO_HANDLE_AT 303
#define SWI_OPEN_BY_HANDLE_AT 304
#define SWI_CLOCK_ADJTIME 305
#define SWI_SYNCFS 306
#define SWI_SENDMMSG 307
#define SWI_SETNS 308
#define SWI_GETCPU 309
#define SWI_PROCESS_VM_READV 310
#define SWI_PROCESS_VM_WRITEV 311
#define SWI_KCMP 312
#define SWI_FINIT_MODULE 313

#elif SWI_MODE == SWI_MODE_ARMEABI

#define SWI_RESTART_SYSCALL 0
#define SWI_EXIT 1
#define SWI_FORK 2
#define SWI_READ 3
#define SWI_WRITE 4
#define SWI_OPEN 5
#define SWI_CLOSE 6
#define SWI_CREAT 8
#define SWI_LINK 9
#define SWI_UNLINK 10
#define SWI_EXECVE 11
#define SWI_CHDIR 12
#define SWI_MKNOD 14
#define SWI_CHMOD 15
#define SWI_LCHOWN 16
#define SWI_LSEEK 19
#define SWI_GETPID 20
#define SWI_MOUNT 21
#define SWI_SETUID 23
#define SWI_GETUID 24
#define SWI_PTRACE 26
#define SWI_PAUSE 29
#define SWI_ACCESS 33
#define SWI_NICE 34
#define SWI_SYNC 36
#define SWI_KILL 37
#define SWI_RENAME 38
#define SWI_MKDIR 39
#define SWI_RMDIR 40
#define SWI_DUP 41
#define SWI_PIPE 42
#define SWI_TIMES 43
#define SWI_BRK 45
#define SWI_SETGID 46
#define SWI_GETGID 47
#define SWI_GETEUID 49
#define SWI_GETEGID 50
#define SWI_ACCT 51
#define SWI_UMOUNT2 52
#define SWI_IOCTL 54
#define SWI_FCNTL 55
#define SWI_SETPGID 57
#define SWI_UMASK 60
#define SWI_CHROOT 61
#define SWI_USTAT 62
#define SWI_DUP2 63
#define SWI_GETPPID 64
#define SWI_GETPGRP 65
#define SWI_SETSID 66
#define SWI_SIGACTION 67
#define SWI_SETREUID 70
#define SWI_SETREGID 71
#define SWI_SIGSUSPEND 72
#define SWI_SIGPENDING 73
#define SWI_SETHOSTNAME 74
#define SWI_SETRLIMIT 75
#define SWI_GETRUSAGE 77
#define SWI_GETTIMEOFDAY 78
#define SWI_SETTIMEOFDAY 79
#define SWI_GETGROUPS 80
#define SWI_SETGROUPS 81
#define SWI_SYMLINK 83
#define SWI_READLINK 85
#define SWI_USELIB 86
#define SWI_SWAPON 87
#define SWI_REBOOT 88
#define SWI_MUNMAP 91
#define SWI_TRUNCATE 92
#define SWI_FTRUNCATE 93
#define SWI_FCHMOD 94
#define SWI_FCHOWN 95
#define SWI_GETPRIORITY 96
#define SWI_SETPRIORITY 97
#define SWI_STATFS 99
#define SWI_FSTATFS 100
#define SWI_SYSLOG 103
#define SWI_SETITIMER 104
#define SWI_GETITIMER 105
#define SWI_STAT 106
#define SWI_LSTAT 107
#define SWI_FSTAT 108
#define SWI_VHANGUP 111
#define SWI_WAIT4 114
#define SWI_SWAPOFF 115
#define SWI_SYSINFO 116
#define SWI_FSYNC 118
#define SWI_SIGRETURN 119
#define SWI_CLONE 120
#define SWI_SETDOMAINNAME 121
#define SWI_UNAME 122
#define SWI_ADJTIMEX 124
#define SWI_MPROTECT 125
#define SWI_SIGPROCMASK 126
#define SWI_INIT_MODULE 128
#define SWI_DELETE_MODULE 129
#define SWI_QUOTACTL 131
#define SWI_GETPGID 132
#define SWI_FCHDIR 133
#define SWI_BDFLUSH 134
#define SWI_SYSFS 135
#define SWI_PERSONALITY 136
#define SWI_SETFSUID 138
#define SWI_SETFSGID 139
#define SWI__LLSEEK 140
#define SWI_GETDENTS 141
#define SWI__NEWSELECT 142
#define SWI_FLOCK 143
#define SWI_MSYNC 144
#define SWI_READV 145
#define SWI_WRITEV 146
#define SWI_GETSID 147
#define SWI_FDATASYNC 148
#define SWI__SYSCTL 149
#define SWI_MLOCK 150
#define SWI_MUNLOCK 151
#define SWI_MLOCKALL 152
#define SWI_MUNLOCKALL 153
#define SWI_SCHED_SETPARAM 154
#define SWI_SCHED_GETPARAM 155
#define SWI_SCHED_SETSCHEDULER 156
#define SWI_SCHED_GETSCHEDULER 157
#define SWI_SCHED_YIELD 158
#define SWI_SCHED_GET_PRIORITY_MAX 159
#define SWI_SCHED_GET_PRIORITY_MIN 160
#define SWI_SCHED_RR_GET_INTERVAL 161
#define SWI_NANOSLEEP 162
#define SWI_MREMAP 163
#define SWI_SETRESUID 164
#define SWI_GETRESUID 165
#define SWI_POLL 168
#define SWI_NFSSERVCTL 169
#define SWI_SETRESGID 170
#define SWI_GETRESGID 171
#define SWI_PRCTL 172
#define SWI_RT_SIGRETURN 173
#define SWI_RT_SIGACTION 174
#define SWI_RT_SIGPROCMASK 175
#define SWI_RT_SIGPENDING 176
#define SWI_RT_SIGTIMEDWAIT 177
#define SWI_RT_SIGQUEUEINFO 178
#define SWI_RT_SIGSUSPEND 179
#define SWI_PREAD64 180
#define SWI_PWRITE64 181
#define SWI_CHOWN 182
#define SWI_GETCWD 183
#define SWI_CAPGET 184
#define SWI_CAPSET 185
#define SWI_SIGALTSTACK 186
#define SWI_SENDFILE 187
#define SWI_VFORK 190
#define SWI_UGETRLIMIT 191
#define SWI_MMAP2 192
#define SWI_TRUNCATE64 193
#define SWI_FTRUNCATE64 194
#define SWI_STAT64 195
#define SWI_LSTAT64 196
#define SWI_FSTAT64 197
#define SWI_LCHOWN32 198
#define SWI_GETUID32 199
#define SWI_GETGID32 200
#define SWI_GETEUID32 201
#define SWI_GETEGID32 202
#define SWI_SETREUID32 203
#define SWI_SETREGID32 204
#define SWI_GETGROUPS32 205
#define SWI_SETGROUPS32 206
#define SWI_FCHOWN32 207
#define SWI_SETRESUID32 208
#define SWI_GETRESUID32 209
#define SWI_SETRESGID32 210
#define SWI_GETRESGID32 211
#define SWI_CHOWN32 212
#define SWI_SETUID32 213
#define SWI_SETGID32 214
#define SWI_SETFSUID32 215
#define SWI_SETFSGID32 216
#define SWI_GETDENTS64 217
#define SWI_PIVOT_ROOT 218
#define SWI_MINCORE 219
#define SWI_MADVISE 220
#define SWI_FCNTL64 221
#define SWI_GETTID 224
#define SWI_READAHEAD 225
#define SWI_SETXATTR 226
#define SWI_LSETXATTR 227
#define SWI_FSETXATTR 228
#define SWI_GETXATTR 229
#define SWI_LGETXATTR 230
#define SWI_FGETXATTR 231
#define SWI_LISTXATTR 232
#define SWI_LLISTXATTR 233
#define SWI_FLISTXATTR 234
#define SWI_REMOVEXATTR 235
#define SWI_LREMOVEXATTR 236
#define SWI_FREMOVEXATTR 237
#define SWI_TKILL 238
#define SWI_SENDFILE64 239
#define SWI_FUTEX 240
#define SWI_SCHED_SETAFFINITY 241
#define SWI_SCHED_GETAFFINITY 242
#define SWI_IO_SETUP 243
#define SWI_IO_DESTROY 244
#define SWI_IO_GETEVENTS 245
#define SWI_IO_SUBMIT 246
#define SWI_IO_CANCEL 247
#define SWI_EXIT_GROUP 248
#define SWI_LOOKUP_DCOOKIE 249
#define SWI_EPOLL_CREATE 250
#define SWI_EPOLL_CTL 251
#define SWI_EPOLL_WAIT 252
#define SWI_REMAP_FILE_PAGES 253
#define SWI_SET_TID_ADDRESS 256
#define SWI_TIMER_CREATE 257
#define SWI_TIMER_SETTIME 258
#define SWI_TIMER_GETTIME 259
#define SWI_TIMER_GETOVERRUN 260
#define SWI_TIMER_DELETE 261
#define SWI_CLOCK_SETTIME 262
#define SWI_CLOCK_GETTIME 263
#define SWI_CLOCK_GETRES 264
#define SWI_CLOCK_NANOSLEEP 265
#define SWI_STATFS64 266
#define SWI_FSTATFS64 267
#define SWI_TGKILL 268
#define SWI_UTIMES 269
#define SWI_ARM_FADVISE64_64 270
#define SWI_PCICONFIG_IOBASE 271
#define SWI_PCICONFIG_READ 272
#define SWI_PCICONFIG_WRITE 273
#define SWI_MQ_OPEN 274
#define SWI_MQ_UNLINK 275
#define SWI_MQ_TIMEDSEND 276
#define SWI_MQ_TIMEDRECEIVE 277
#define SWI_MQ_NOTIFY 278
#define SWI_MQ_GETSETATTR 279
#define SWI_WAITID 280
#define SWI_SOCKET 281
#define SWI_BIND 282
#define SWI_CONNECT 283
#define SWI_LISTEN 284
#define SWI_ACCEPT 285
#define SWI_GETSOCKNAME 286
#define SWI_GETPEERNAME 287
#define SWI_SOCKETPAIR 288
#define SWI_SEND 289
#define SWI_SENDTO 290
#define SWI_RECV 291
#define SWI_RECVFROM 292
#define SWI_SHUTDOWN 293
#define SWI_SETSOCKOPT 294
#define SWI_GETSOCKOPT 295
#define SWI_SENDMSG 296
#define SWI_RECVMSG 297
#define SWI_SEMOP 298
#define SWI_SEMGET 299
#define SWI_SEMCTL 300
#define SWI_MSGSND 301
#define SWI_MSGRCV 302
#define SWI_MSGGET 303
#define SWI_MSGCTL 304
#define SWI_SHMAT 305
#define SWI_SHMDT 306
#define SWI_SHMGET 307
#define SWI_SHMCTL 308
#define SWI_ADD_KEY 309
#define SWI_REQUEST_KEY 310
#define SWI_KEYCTL 311
#define SWI_SEMTIMEDOP 312
#define SWI_VSERVER 313
#define SWI_IOPRIO_SET 314
#define SWI_IOPRIO_GET 315
#define SWI_INOTIFY_INIT 316
#define SWI_INOTIFY_ADD_WATCH 317
#define SWI_INOTIFY_RM_WATCH 318
#define SWI_MBIND 319
#define SWI_GET_MEMPOLICY 320
#define SWI_SET_MEMPOLICY 321
#define SWI_OPENAT 322
#define SWI_MKDIRAT 323
#define SWI_MKNODAT 324
#define SWI_FCHOWNAT 325
#define SWI_FUTIMESAT 326
#define SWI_FSTATAT64 327
#define SWI_UNLINKAT 328
#define SWI_RENAMEAT 329
#define SWI_LINKAT 330
#define SWI_SYMLINKAT 331
#define SWI_READLINKAT 332
#define SWI_FCHMODAT 333
#define SWI_FACCESSAT 334
#define SWI_PSELECT6 335
#define SWI_PPOLL 336
#define SWI_UNSHARE 337
#define SWI_SET_ROBUST_LIST 338
#define SWI_GET_ROBUST_LIST 339
#define SWI_SPLICE 340
#define SWI_ARM_SYNC_FILE_RANGE 341
#define SWI_SYNC_FILE_RANGE2 341
#define SWI_TEE 342
#define SWI_VMSPLICE 343
#define SWI_MOVE_PAGES 344
#define SWI_GETCPU 345
#define SWI_EPOLL_PWAIT 346
#define SWI_KEXEC_LOAD 347
#define SWI_UTIMENSAT 348
#define SWI_SIGNALFD 349
#define SWI_TIMERFD_CREATE 350
#define SWI_EVENTFD 351
#define SWI_FALLOCATE 352
#define SWI_TIMERFD_SETTIME 353
#define SWI_TIMERFD_GETTIME 354
#define SWI_SIGNALFD4 355
#define SWI_EVENTFD2 356
#define SWI_EPOLL_CREATE1 357
#define SWI_DUP3 358
#define SWI_PIPE2 359
#define SWI_INOTIFY_INIT1 360
#define SWI_PREADV 361
#define SWI_PWRITEV 362
#define SWI_RT_TGSIGQUEUEINFO 363
#define SWI_PERF_EVENT_OPEN 364
#define SWI_RECVMMSG 365
#define SWI_ACCEPT4 366
#define SWI_FANOTIFY_INIT 367
#define SWI_FANOTIFY_MARK 368
#define SWI_PRLIMIT64 369
#define SWI_NAME_TO_HANDLE_AT 370
#define SWI_OPEN_BY_HANDLE_AT 371
#define SWI_CLOCK_ADJTIME 372
#define SWI_SYNCFS 373
#define SWI_SENDMMSG 374
#define SWI_SETNS 375
#define SWI_PROCESS_VM_READV 376
#define SWI_PROCESS_VM_WRITEV 377
#define SWI_KCMP 378
#define SWI_FINIT_MODULE 379
#define SWI_SCHED_SETATTR 380
#define SWI_SCHED_GETATTR 381
#define SWI_RENAMEAT2 382
#define SWI_SECCOMP 383
#define SWI_GETRANDOM 384
#define SWI_MEMFD_CREATE 385
#define SWI_BPF 386
#define SWI_EXECVEAT 387
#define SWI_USERFAULTFD 388
#define SWI_MEMBARRIER 389
#define SWI_MLOCK2 390
#define SWI_COPY_FILE_RANGE 391
#define SWI_PREADV2 392
#define SWI_PWRITEV2 393
#define SWI_PKEY_MPROTECT 394
#define SWI_PKEY_ALLOC 395
#define SWI_PKEY_FREE 396
#define SWI_STATX 397
#define SWI_ARM_BREAKPOINT 983041
#define SWI_ARM_CACHEFLUSH 983042
#define SWI_ARM_USR26 983043
#define SWI_ARM_USR32 983044
#define SWI_ARM_SET_TLS 983045


#define SWI_GET_US_COUNT    40000

#endif
