#include<cstddef>
#include<cassert>
/*
 * We are implementing our code within the header file. This is only acceptable for templates
 * We would get an error if we split it into header and implementation files
*/


template <typename T>
class SingleList {
	private:
		struct _node{
			T data;
			struct _node* next;
		};

		/*Below is called type aliasing*/
		using Node = struct _node;
		/*Alternative is 
		 * typedef Node struct _node;*/

		Node* _first;
		Node* _last;
		std::size_t _size;

		void reccopy(Node* ptr) {
			if(ptr) {
				push_front(ptr->data);
				recopy(ptr->next);
			}
		}
	public:
		SingleList() : _first{nullptr}, _last{nullptr}, _size{0} {}
		
		SingleList(const SingleList& sl) : _first{nullptr}, _last{nullptr}, _size{0} {
			recopy{sl._first}
		}

		~SingleList() {
			while (!empty()){
				pop_front();
			}
		}

		T front() const{
			return _first->data;
		}
		
		T last() const{
			return _last->data;
		}

		std::size t size() const {
			return _size;
		}

		void push_back(T value){
			SingleList* item = new Node;
			item->data = value;
			item->next = nullptr;
			if(empty()){
				_first = item;
				}
			else{
				_last->next = item;
				}
			_last = item;
			_size++;
		}

		void push_front(T value){
			SingleList* item = new Node;
			item->data = value;
			if(empty()){
				_last = item;
				}
			else{
				item->next = _first;
				}
			_first = item;
			_size++;

		}

		void pop_front(){
			/*if(empty()){
				return;	
			}
			 */
			assert(!empty());
			SingleList* node_to_delete = _first;
			if(_size = 1){
				_first = nullptr;
				_last = nullptr;
				}
			else{
				_first = _first->next;
				}
			delete node_to_delete;
			size--;

		}

		void pop_back(){
			assert(!empty());
			SingleList* node_to_delete = _last;
			if(_size = 1){
				_first = nullptr;
				_last = nullptr;
			}
			else{
				//define new _last
				SingleList* new_last = _first;
				while(new_last->next != _last){
					new_last = new_last->next;
				}
				_last = new_last;
				_last->next = nullptr;
			}
			delete node_to_delete;
			size--;
		}

		bool empty() const {
			return (_first == nullptr) && (_last == nullptr)\
							&& (_size == 0);
		}
};
