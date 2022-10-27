#include<cstddef>

/*We are implementing our code within the header file. This is only acceptable for templates
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
		/*Alternative is typedef Node struct _node;*/

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

		bool empty() const {
			return (_first == nullptr) && (_last == nullptr)\
							&& (_size == 0);
		}


};
