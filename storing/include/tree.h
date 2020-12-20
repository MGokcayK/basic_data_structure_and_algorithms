/*
*	@Author : Mehmet Gokcay Kabatas - github/MGokcayK
*
*	Creating basic binary tree structure.
*
*	Date : 20/12/2020
*		Create structures.
*/
#pragma once 
#include <iostream>

namespace gstr
{
	/// <summary>
	/// Basic binary tree class. It is templated. 
	/// <para>
	/// It accept primitives such as  `int`, `float`, 
	/// `double`, 'char`,`string` etc. or custom 
	/// structures. 
	/// </para>
	/// </summary>
	/// <typeparam name="Dtype"></typeparam>
	template <class Dtype>
	class binaryTree
	{
	private:

		// basic node structure
		struct Node
		{
			Dtype data;
			Node* leftNode;
			Node* rightNode;
		};

		// root node
		Node* root;
		
		// print in inorder of node
		void pr_inorder(Node* node)
		{
			if (node != nullptr)
			{
				pr_inorder(node->leftNode);
				std::cout << node->data << std::endl;
				pr_inorder(node->rightNode);
			}			
		}

		// print in preorder of node
		void pr_preorder(Node* node)
		{
			if (node != nullptr)
			{
				std::cout << node->data << std::endl;
				pr_preorder(node->leftNode);
				pr_preorder(node->rightNode);
			}
		}

		// print in postorder of node
		void pr_postorder(Node* node)
		{
			if (node != nullptr)
			{
				pr_postorder(node->leftNode);
				pr_postorder(node->rightNode);
				std::cout << node->data << std::endl;
			}
		}

	public:

		/// <summary>
		/// Default Constructor which makes root as nullptr.
		/// </summary>
		binaryTree()
		{
			this->root = nullptr;
		};


		/// <summary>
		/// Add Node to tree.
		/// </summary>
		/// <param name="data">: data of new node.</param>
		/// <param name="print">: printing related info when add new data.</param>
		void addNode(Dtype data, bool print = false)
		{
			// Temporary node created
			Node* temp = new Node;
			temp->data = data;
			temp->leftNode = nullptr;
			temp->rightNode = nullptr;

			if (this->root == nullptr)
			{				
				// Main root node created
				this->root = temp;
				
				if (print==true)
				std::cout << " Main Root Node Crated : " << this->root->data << std::endl;
			}
			else
			{
				// Store main root adress temporary.
				Node* main_root = this->root;

				// Counter for new data whether it is added already or not.
				int c = 0;

				// Loop for adding.
				while (this->root != nullptr)
				{
					// If new data is less than current node, add to left.
					if (temp->data < this->root->data)
					{
						if (this->root->leftNode != nullptr)
						{
							this->root = this->root->leftNode;
						}
						else
						{
							c += 1;
							this->root->leftNode = temp;
							
							if (print == true)
							std::cout << " Left Node Crated : " << temp->data  << " to Parent Node : "<<
								this->root->data << std::endl;
						}
						
					}
					// If new data is greater than current node, add to right.
					else if (temp->data > this->root->data)
					{
						if (this->root->rightNode != nullptr)
						{
							this->root = this->root->rightNode;
						}
						else
						{
							c += 1;
							this->root->rightNode = temp;
							
							if (print == true)
							std::cout << " Right Node Crated : " << temp->data << " to Parent Node : " <<
								this->root->data << std::endl;
						}
					}
					// If new data already in tree, nothing to add.
					else
					{
						if (print == true)
						if (c==0) std::cout << "Data (" << temp->data << ") is already in tree. Therefore, it did not add to tree!" << std::endl;
						break;
					}
					
				}
				// return original root.
				this->root = main_root;
			}
		};

		
		/// <summary>
		/// Printing tree in inorder.
		/// </summary>
		void inorder()
		{
			pr_inorder(this->root);
		}

		/// <summary>
		/// Printing tree in preorder.
		/// </summary>
		void preorder()
		{
			pr_preorder(this->root);
		}

		/// <summary>
		/// Printing tree in postorder.
		/// </summary>
		void postorder()
		{
			pr_postorder(this->root);
		}
	
	};



}