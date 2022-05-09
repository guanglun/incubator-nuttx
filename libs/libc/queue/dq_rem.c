/****************************************************************************
 * libs/libc/queue/dq_rem.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <queue.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: dq_rem
 *
 * Description:
 *   dq_rem removes 'node' from 'queue'
 *
 ****************************************************************************/

void __attribute__ ((section(".iram1"))) dq_rem(FAR dq_entry_t *node, dq_queue_t *queue)
{
  FAR dq_entry_t *prev = node->blink;
  FAR dq_entry_t *next = node->flink;

  if (!prev)
    {
      queue->head = next;
    }
  else
    {
      prev->flink = next;
    }

  if (!next)
    {
      queue->tail = prev;
    }
  else
    {
      next->blink = prev;
    }

  node->flink = NULL;
  node->blink = NULL;
}
