
 # include <iostream.h> 
  
 template <class T> 
 class List ; 
  
  
 template <class T> 
 class Node 
 { 
  T data ; 
  Node<T> *next ; 
 public: 
  Node(){} 
  Node(T data, Node<T>* next = NULL) : data(data), next(next){} 
  void setNext(Node<T>* next){ this->next = next ; } 
  void setData(T data){ this->data = data ; } 
  T getData(){ return data ; } 
  ~Node() ; 
  friend class List<T> ; 
 } ; 
  
 template <class T> 
 Node<T>::~Node() 
 { 
  if ( next != NULL )  
  { 
   delete next ;  
   next = NULL ; 
  } 
 } 
  
 template <class T> 
 class List 
 { 
  Node<T> *head, *tail ; 
  int length ; 
  
 protected: 
  Node<T>* operator()(int pos) ;    //pointer to a node in the list 
  
 public: 
  List(Node<T>* head=NULL): head(head){tail = NULL ; length = 0 ;} 
  Node<T>* getHead(){ return head ; } 
  Node<T>* getTail(){ return tail ; } 
  void append(T data) ; 
  void loopify(int pos) ;      //creates a loop  
  void unloopify(){ tail->next = NULL ; }  //removes the loop 
  void traverse(void (*visit)(Node<T>*)) ; //user defined traverse 
  void free(){ delete head ; } 
  T operator[](int pos) ;//data of a node in the list 
  bool detectLoop() ; 
  void removeLoop() ; 
  static List<T> makeList(T arr[], int len) ; //factory-like function 
  ~List(){ unloopify() ; free() ; } 
 } ; 
  
 template <class T> 
 void List<T>::append(T data) 
 { 
  if( head == NULL ) 
  { 
   head = tail = new Node<T>(data) ; 
  } 
  else 
  { 
   tail->next = new Node<T>(data) ; 
   tail = tail->next ; 
  } 
  length ++ ; 
 } 
  
 template <class T> 
 void List<T>::loopify(int pos) 
 { 
  if( length == 0 || pos < 0 || pos >= length ) 
   return ; 
  tail->next = operator()(pos) ; 
 } 
  
 template <class T> 
 List<T> List<T>::makeList(T arr[], int len) 
 { 
  List<T>* list = new List<T> ; 
  for(int i=0; i<len; i++) 
  { 
   list->append(arr[i]) ; 
  } 
  return *list ;  
  //imp: else deallocation! 
  //this method is better than returning ref of local var also 
 } 
  
 template <class T> 
 Node<T>* List<T>::operator ()(int pos) 
 { 
  if( length == 0 || pos < 0 || pos >= length ) 
   return NULL ; 
  Node<T>* ptr = head ; 
  for(int i=0; i<pos; i++, ptr = ptr->next) ;  
  return ptr ; 
 } 
  
 template <class T> 
 T List<T>::operator [](int pos) 
 { 
  Node<T>* node = operator()(pos) ; 
  if( node != NULL ) 
   return node->data ; 
  return T() ; 
 } 
  
 template <class T> 
 void List<T>::traverse(void (*visit)(Node<T>*)) 
 { 
  Node<T>* ptr = head ; 
  for(int i=0; i<length; i++, ptr=ptr->next) 
  { 
   visit(ptr) ; 
  } 
  if( tail != NULL && tail->next != NULL ) 
   visit(tail->next) ; 
  //visit the tail again in the end 
 } 
  
 template <class T> 
 bool List<T>::detectLoop() 
 { 
  if( head == NULL ) 
   return false ; 
  Node<T> *ptr1 = head, *ptr2 = head ; 
  
  do 
  { 
   ptr1 = ptr1->next ; 
   ptr2 = ptr2->next ; 
   if( ptr2 != NULL ) 
    ptr2 = ptr2->next ; 
  } 
  while( ptr2 != NULL && ptr2 != ptr1 ) ; 
  
  return (ptr2 == ptr1) && (ptr2 != NULL) ; 
  //without this second clause it was a big bug! 
 } 
  
 template <class T> 
 void List<T>::removeLoop() 
 { 
  if( head == NULL ) 
   return ; 
  Node<T> *ptr1 = head, *ptr2 = head ; 
  
  do 
  { 
   ptr1 = ptr1->next ; 
   ptr2 = ptr2->next ; 
   if( ptr2 != NULL ) 
    ptr2 = ptr2->next ; 
  } 
  while( ptr2 != NULL && ptr2 != ptr1 ) ; 
  
  if ( ptr2 == NULL ) 
   return ; 
  
  if( ptr2 == head )    //for fully circular lists!  
  { 
   while(ptr2->next != head ) 
    ptr2 = ptr2->next ; 
   ptr2->next = NULL ;   
   return ; 
  } 
  
  ptr1 = head ; 
  
  while( ptr1->next != ptr2->next ) 
  { 
   ptr1 = ptr1->next ; 
   ptr2 = ptr2->next ; 
  } 
  ptr2->next = NULL ; 
 } 
  
 template <class T> 
 void print(Node<T>* node) 
 { 
  cout<<node->getData() ; 
 } 
  
 void main() 
 { 
  char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' } ; 
  List<char> list = List<char>::makeList(arr, 8) ;  
   
  list.traverse(print<char>) ; 
  cout<<"\n"<<list[4] ; 
  
  list.loopify(0) ; 
  cout<<"\n" ; 
  list.traverse(print<char>) ; 
  cout<<(list.detectLoop()? "\nloop": "\nnoloop") ; 
  list.removeLoop() ; 
  cout<<(list.detectLoop()? "\nloop": "\nnoloop") ; 
  
  list.loopify(3) ; 
  cout<<"\n" ; 
  list.traverse(print<char>) ; 
  cout<<(list.detectLoop()? "\nloop": "\nnoloop") ; 
  list.removeLoop() ; 
  cout<<(list.detectLoop()? "\nloop": "\nnoloop") ; 
  
 } 
