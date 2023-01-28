#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::pop_back(){   
  if (head_ == nullptr){ 
      return;
  }
  tail_->last--;
  if (head_==tail_ && head_->first == head_->last){
      head_ = nullptr;
  }
  else if(head_->first == head_->last){         
      tail_=tail_->prev;
      delete tail_->next;
      tail_->next = nullptr; 
  }
    size_--;
  }

void ULListStr::push_back(const std::string& val){    
    if (head_ == nullptr){
      Item* t = new Item();
      t->val[0] = val;
      t->last = 1;
      head_ = t;
      tail_ = t;
    }
    else if (tail_->last == 10){          
      Item* t = new Item();      
      t->val[0] = val;
      t->last = 1;
      tail_->next = t;
      t->next = nullptr;
      t->prev = tail_;
      tail_=t;
    }
    else{
      tail_->val[tail_->last] = val;
      tail_->last++;
    }
    size_++;               
  }

void ULListStr::push_front(const std::string& val){     
  if (head_ == nullptr){
    Item* t = new Item();
    t->val[9] = val; 
    t->last = 10;                 
    t->first = 9;
    head_ = t;
    tail_ = t;
  }
  else if(head_->first == 0){
    Item* t = new Item();
    t->val[9] = val;
    t->first = 9; 
    t->last = 10;                  
    head_->prev = t;  
    t->prev = nullptr;            
    t->next = head_;
    head_ = t;
  }
  else{
    head_->val[head_->first - 1] = val;
    head_->first--;
  }
  size_++;

}

void ULListStr::pop_front(){       
  if (head_ == nullptr){
    return;
  }
  head_->first++;

  if (head_==tail_ && head_->last == head_->first){
      head_ = nullptr;
  }

  else if (head_->last == head_->first){        
    head_ = head_->next;
    delete head_->prev;
    head_->prev = nullptr;

  }
size_--;
}

std::string const & ULListStr::back() const{       

  int p = tail_->last - 1;
  return tail_->val[p];

}

std::string const & ULListStr::front() const{     

  int p = head_->first;
  return head_->val[p];

}
std::string* ULListStr::getValAtLoc(size_t loc) const{         
  if (head_ == nullptr){
    return nullptr;
  }
  Item* t = nullptr; 
  t = head_;
  unsigned int c = 0;             
  unsigned int in = 0;
  for (in = head_->first; c!= size_ + head_->first; c++){
     if (c == loc){           
      break;
    }
    if (in == (t->last) - 1){
      t = t->next;
      in = 0;
    }
    else{
      in++;
    }
  }
  return &(t->val[in]);
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

