#include <iostream>
#include <map>
#include <ConsoleEngine/EngineDebug.h>

typedef int KeyType;
typedef int DataType;

class MyPair
{
public:
	MyPair()
	{
	}
	MyPair(KeyType _Key, DataType _Value)
		: Key(_Key), Value(_Value)
	{
	}

	KeyType Key = KeyType();
	DataType Value = DataType();
};

class MyMap
{
private:
	class MapNode
	{
	public:
		MyPair Pair;
		MapNode* Parent = nullptr;
		MapNode* LeftChild = nullptr;
		MapNode* RightChild = nullptr;

		void InsertNode(MapNode* _Node)
		{
			_Node->Parent = this;

			if (Pair.Key > _Node->Pair.Key)
			{
				if (nullptr == this->LeftChild)
				{
					this->LeftChild = _Node;
					return;
				}

				LeftChild->InsertNode(_Node);
			}

			if (Pair.Key < _Node->Pair.Key)
			{
				if (nullptr == RightChild)
				{
					RightChild = _Node;
					return;
				}

				RightChild->InsertNode(_Node);
			}

			return;
		}

		bool ContainsNode(const KeyType& _Key)
		{
			if (Pair.Key == _Key)
			{
				return true;
			}

			if (Pair.Key > _Key)
			{
				if (nullptr != LeftChild)
				{
					return LeftChild->ContainsNode(_Key);
				}
			}

			if (Pair.Key < _Key)
			{
				if (nullptr != RightChild)
				{
					RightChild->ContainsNode(_Key);
				}
			}

			return false;
		}

		MapNode* findNode(const KeyType& _Key)
		{
			if (Pair.Key == _Key)
			{
				return this;
			}

			if (Pair.Key > _Key)
			{
				if (nullptr != LeftChild)
				{
					return LeftChild->findNode(_Key);
				}
			}

			if (Pair.Key < _Key)
			{
				if (nullptr != RightChild)
				{
					return RightChild->findNode(_Key);
				}
			}
			return nullptr;
		}

		MapNode* minnode()
		{
			if (nullptr == LeftChild)
			{
				return this;
			}

			return LeftChild->minnode();
		}

		MapNode* maxnode()
		{
			if (nullptr == RightChild)
			{
				return this;
			}

			return RightChild->maxnode();
		}

		MapNode* OverParent()
		{
			MapNode* PNode = Parent;

			while (PNode)
			{
				if (PNode->Pair.Key > Pair.Key)
				{
					return PNode;
				}

				PNode = PNode->Parent;
			}

			return nullptr;
		}

		MapNode* SmallParent()
		{
			MapNode* PNode = Parent;

			while (PNode)
			{
				if (PNode->Pair.Key < Pair.Key)
				{
					return PNode;
				}

				PNode = PNode->Parent;
			}

			return nullptr;
		}

		MapNode* NextNode()
		{
			if (nullptr != RightChild)
			{
				return RightChild->minnode();
			}

			return OverParent();
		}

		MapNode* PrevNode()
		{
			if (nullptr != this->LeftChild)
			{
				return this->LeftChild->maxnode();
			}

			return SmallParent();
		}

		bool IsLeaf()
		{
			return nullptr == LeftChild && nullptr == RightChild;
		}

		void Release()
		{
			if (nullptr != Parent)
			{
				if (Parent->LeftChild == this)
				{
					Parent->LeftChild = nullptr;
				}

				if (Parent->RightChild == this)
				{
					Parent->RightChild = nullptr;
				}
			}
		}

		void lastorderdelete()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->lastorderdelete();
			}
			if (nullptr != RightChild)
			{
				RightChild->lastorderdelete();
			}
			delete this;
		}
		
		void firstOrderPrint()
		{
			std::cout << Pair.Key << std::endl;
			if (nullptr != LeftChild)
			{
				LeftChild->firstOrderPrint();
			}
			if (nullptr != RightChild)
			{
				RightChild->firstOrderPrint();
			}

		}

		void midOrderPrint()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->midOrderPrint();
			}
			std::cout << Pair.Key << std::endl;
			if (nullptr != RightChild)
			{
				RightChild->midOrderPrint();
			}
		}

		void lastOrderPrint()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->lastOrderPrint();
			}
			if (nullptr != RightChild)
			{
				RightChild->lastOrderPrint();
			}
			std::cout << Pair.Key << std::endl;
			delete this;
		}
	protected:

	private:

	};

public:
	class iterator
	{
		friend MyMap;
	public:
		iterator()
		{
		}
		iterator(MapNode* _CurNode)
			: CurNode(_CurNode)
		{
		}
		
		MyPair* operator->()
		{
			MyPair& MapPair = CurNode->Pair;
			return &MapPair;
		}

		bool operator!=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		void operator++()
		{
			CurNode = CurNode->NextNode();
		}

	protected:

	private:
		MapNode* CurNode = nullptr;
	};

	~MyMap()
	{
		clear();
	}

	void insert(const MyPair& _Value)
	{
		MapNode* NewNode = new MapNode();
		NewNode->Pair = _Value;

		if (nullptr == Root)
		{
			Root = NewNode;
			return;
		}

		Root->InsertNode(NewNode);
	}

	bool contains(const KeyType& _Key)
	{
		if (nullptr == Root)
		{
			return false;
		}

		return Root->ContainsNode(_Key);
	}

	iterator begin()
	{
		if (nullptr == Root)
		{
			return end();
		}

		return iterator(Root->minnode());
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	iterator find(const KeyType& _Key)
	{
		if (nullptr == Root)
		{
			return end();
		}

		return iterator(Root->findNode(_Key));
	}

	iterator erase(iterator& _Iter)
	{
		iterator Return;

		if (nullptr == _Iter.CurNode)
		{
			MsgBoxAssert("유효하지 않은 원소를 삭제하려고 했습니다.");
			return Return;
		}
		
		MapNode* NextNode = _Iter.CurNode->NextNode();
		
		Return.CurNode = NextNode;

		if (true == _Iter.CurNode->IsLeaf())
		{
			MapNode* ParentNode = _Iter.CurNode->Parent;
			_Iter.CurNode->Release();
			delete _Iter.CurNode;
			return Return;
		}

		MapNode* ChangeNode = nullptr;
		MapNode* CurNode = _Iter.CurNode;

		ChangeNode = CurNode->RightChild->minnode();
		if (nullptr == ChangeNode)
		{
			ChangeNode = CurNode->LeftChild->maxnode();
		}

		if (nullptr == ChangeNode)
		{
			MsgBoxAssert("체인지 노드 에러.");
			return Return;
		}
		ChangeNode->Release();

		MapNode* LeftChild = CurNode->LeftChild;
		MapNode* RightChild = CurNode->RightChild;

		if (nullptr != LeftChild)
		{
			LeftChild->Parent = nullptr;
		}
		if (nullptr != RightChild)
		{
			RightChild->Parent = nullptr;
		}
		if (nullptr != LeftChild)
		{
			LeftChild->Parent = ChangeNode;
			if (CurNode->LeftChild != ChangeNode)
			{
				ChangeNode->LeftChild = LeftChild;
			}
		}
		if (nullptr != RightChild)
		{
			RightChild->Parent = ChangeNode;
			if (CurNode->RightChild != ChangeNode)
			{
				ChangeNode->RightChild = RightChild;
			}
		}

		ChangeNode->Parent = CurNode->Parent;
		MapNode* Parent = ChangeNode->Parent;
		if (nullptr != Parent && Parent->LeftChild == CurNode)
		{
			Parent->LeftChild = ChangeNode;
		}

		if (nullptr != Parent && Parent->RightChild == CurNode)
		{
			Parent->RightChild = ChangeNode;
		}

		if (Root == CurNode)
		{
			Root = ChangeNode;
		}

		delete CurNode;
		return Return;
	}

	void clear()
	{
		Root->lastorderdelete();
	}
	void firstOrderPrint()
	{
		Root->firstOrderPrint();
	}

	void midOrderPrint()
	{
		Root->midOrderPrint();
	}

	void lastOrderPrint()
	{
		Root->lastOrderPrint();
	}
protected:

	MapNode* Root = nullptr;
};

int main()
{
	LeakCheck;
	{
		std::cout << "내 맵" << std::endl;
		//      Key   Value
		MyMap NewMap = MyMap();

		NewMap.insert(MyPair(10, 0));
		NewMap.insert(MyPair(5, 0));
		NewMap.insert(MyPair(15, 0));
		NewMap.insert(MyPair(12, 99));
		NewMap.insert(MyPair(3, 0));
		NewMap.insert(MyPair(7, 0));

		if (true == NewMap.contains(12))
		{
			int a = 0;
		}

		std::cout << "first" << std::endl;
		NewMap.firstOrderPrint();
		std::cout << "mid" << std::endl;
		NewMap.midOrderPrint();
		std::cout << "last" << std::endl;
		NewMap.lastOrderPrint();
	}
}