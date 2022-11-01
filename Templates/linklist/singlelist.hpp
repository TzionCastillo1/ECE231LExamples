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
				push_back(ptr->data);
				recopy(ptr->next);
			}
		}
	public:
		SingleList() : _first{nullptr}, _last{nullptr}, _size{0} {}
		
		SingleList(const SingleList& sl) : _first{nullptr}, _last{nullptr}, _size{0} {
			reccopy(sl._first);
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

		std::size_t size() const {
			return _size;
		}

		void push_back(T value){
			Node* item = new Node;
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
			Node* item = new Node;
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
			Node* node_to_delete = _first;
			if(_size = 1){
				_first = nullptr;
				_last = nullptr;
				}
			else{
				_first = _first->next;
				}
			delete node_to_delete;
			_size--;

		}

		void pop_back(){
			assert(!empty());
			Node* node_to_delete = _last;
			if(_size = 1){
				_first = nullptr;
				_last = nullptr;
			}
			else{
				//define new _last
				Node* new_last = _first;
				while(new_last->next != _last){
					new_last = new_last->next;
				}
				_last = new_last;
				_last->next = nullptr;
			}
			delete node_to_delete;
			_size--;
		}

		bool empty() const {
			return (_first == nullptr) && (_last == nullptr)\
							&& (_size == 0);
		}

		void print() const{	
			Node* elem = _first;
			for(elem = _first; elem != nullptr; elem = elem->next){
				std::cout << elem->data << ' ';
			}
			std::cout << std::endl;
		}

		SingleList& operator=(const SingleList& sl){
			/* Cannot do the following code safely
			 * _first = sl._first;
			 * _last = sl._last;
			 * _size = sl._size;
			 * We could potentially cause a seg-fault, by having two pointers
			 * point to the same address. If one deletes the pointer, the other
			 * pointer can dereference NULL
			 */
			/* //another example
			 * SingleList a;
			 * some loop{
			 *		SingleList b;
			 *		a = b;
			 * }
			 * a.print();
			 *
			 * // b would be deleted after some loop runs, because it exists only
			 * in that scope. a would then point to Null
			 */
			if (this == &sl) {
				return *this;
			}

			while(!empty()) {
				pop_front();
			}
			reccopy(sl._first);

			return *this;

		}

		//We need to create a new template for a friend class, because it
		//exists outside of the scope of the class
		template <typename U>
		friend std::ostream& operator<<(std::ostream& out, SingleList<U>& sl){
			/*Node* elem = _first;
			for(elem = first; elem != nullptr; elem = elem->next;){
				out << elem->data << ' ';
			}
			*/
			//We do not have access to node so we must use something different
			for(auto x = sl._front; x!=nullptr; x = x->next){
				out << x->data << ' ' ;
			}
			return out;	
		}
};
