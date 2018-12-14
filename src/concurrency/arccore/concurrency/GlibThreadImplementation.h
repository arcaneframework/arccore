﻿// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
/*---------------------------------------------------------------------------*/
/* GlibThreadImplementation.h                                  (C) 2000-2018 */
/*                                                                           */
/* Implémentation de ITreadImplementation avec la 'Glib'.                    */
/*---------------------------------------------------------------------------*/
#ifndef ARCCORE_CONCURRENCY_GLIBTHREADIMPLEMENTATION_H
#define ARCCORE_CONCURRENCY_GLIBTHREADIMPLEMENTATION_H
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arccore/concurrency/IThreadImplementation.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arccore
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Implémentation de ITreadImplementation avec la 'Glib'.
 */
class ARCCORE_CONCURRENCY_EXPORT GlibThreadImplementation
: public IThreadImplementation
{
 public:
  GlibThreadImplementation();
  ~GlibThreadImplementation() override;
 public:
  void initialize() override;
 public:
  ThreadImpl* createThread(IFunctor* f) override;
  void joinThread(ThreadImpl* t) override;
  void destroyThread(ThreadImpl* t) override;

  void createSpinLock(Int64* spin_lock_addr) override;
  void lockSpinLock(Int64* spin_lock_addr,Int64* scoped_spin_lock_addr) override;
  void unlockSpinLock(Int64* spin_lock_addr,Int64* scoped_spin_lock_addr) override;

  MutexImpl* createMutex() override;
  void destroyMutex(MutexImpl*) override;
  void lockMutex(MutexImpl* mutex) override;
  void unlockMutex(MutexImpl* mutex) override;

  Int64 currentThread() override;

  IThreadBarrier* createBarrier() override;
 private:
  MutexImpl* m_global_mutex_impl;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arccore

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif
