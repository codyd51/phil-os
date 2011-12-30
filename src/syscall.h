// syscall.h -- Defines the interface for and structures relating to the syscall dispatch system.
// Written for JamesM's kernel development tutorials.

#ifndef SYSCALL_H
#define SYSCALL_H

#include "common.h"
#include "monitor.h"

void initialise_syscalls();

#define DECL_SYSCALL0(fn) int syscall_##fn();
#define DECL_SYSCALL1(fn,p1) int syscall_##fn(p1);
#define DECL_SYSCALL2(fn,p1,p2) int syscall_##fn(p1,p2);

#define DEFN_SYSCALL0(fn, num) \ 
int syscall_##fn() \ 
{ \ 
  int a; \ 
  asm volatile("int $0x80" : "=a" (a) : "0" (num)); \ 
  return a; \ 
}

#define DEFN_SYSCALL1(fn, num, P1) \ 
int syscall_##fn(P1 p1) \ 
{ \ 
  int a; \ 
  asm volatile("int $0x80" : "=a" (a) : "0" (num), "b" ((int)p1)); \ 
  return a; \ 
}

#define DEFN_SYSCALL2(fn, num, P1, P2) \ 
int syscall_##fn(P1 p1, P2 p2) \ 
{ \ 
  int a; \ 
  asm volatile("int $0x80" : "=a" (a) : "0" (num), "b" ((int)p1), "c" ((int)p2)); \ 
  return a; \ 
}

DECL_SYSCALL1(monitor_write, const char*)
DECL_SYSCALL1(monitor_write_hex, const char*)

#endif

