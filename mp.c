/**
 * Thread message passing
 *
 * Messages consist of a type (uint32) and a pointer to the contents of the
 * actual message. When there are no 'clients' listening on the specified
 * message type, the message handler (this file) takes care of freeing the
 * memory allocated for the message. Each given pointer needs to be created
 * through the use of malloc (or equivelant) to enable the free() command
 * on it.
 *
 * THE CONTENTS OF THE MESSAGE POINTS TO THE SAME MEMORY LOCATION FOR ALL
 * LISTENERS. BEFORE MODIFICATIONS, COPYING THE CONTENS WILL BE REQUIRED
 * TO PREVENT RACE-CONDITIONS OR EVEN SEGMENTATION FAULTS.
 *
 * mp_listen(uint32 type)
 *     Returns an id (uint32) you can use to ask the message handler for
 *     available messages. We'll refer to this id (and queue) as 'qid'
 *
 * mp_free(uint32 qid)
 *     Destroys the incoming listener for the qid and unregisters the
 *     listener.
 *
 * mp_read(uint32 qid)
 *     Checks if a message is available. Returns a pointer to the message's
 *     content or 0 if no message was available.
 *
 * mp_done(uint32 qid, void *pointer)
 *     Notify the message handler the listener is done with the message. Once
 *     all listeners are done with the message, free() will be called to
 *     release the used memory.
 *
 * mp_write(uint32 type, void *pointer)
 *     Transmits a message to all queues listening for the given type. If no
 *     listeners are present for the type, the message will be destroyed
 *     through the free() command.
 */