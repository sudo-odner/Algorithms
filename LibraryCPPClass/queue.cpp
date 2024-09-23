#include "queue.h"
#include <stdexcept>

Queue::Queue() : _queue(new List) {
}

Queue::Queue(const Queue &a) : _queue(new List(*a._queue)) {
}

Queue &Queue::operator=(const Queue &a)
{
    return *this;
}

Queue::~Queue(){
    delete _queue;
}

void Queue::insert(Data data){
    _queue->insert(data);
}

Data Queue::get() const {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return _queue->last()->data();
}

void Queue::remove(){
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    if (_queue->last()->prev() == nullptr) {
        _queue->erase_first();
    } else {
        _queue->erase_next(_queue->last()->prev());
    }
}

bool Queue::empty() const {
    return _queue->first() == nullptr;
}
