#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////

    ChatBot(ChatBot &source);   //copy constructor

    ChatBot &operator=(ChatBot &source) // copy assignment operator
    {
        std::cout << "ChatBot Copy Assignment Operator" << std::endl;
        if(this == &source)
            return *this;

        _image = source._image;
        source._image = NULL;
        return *this;
    }

    ChatBot(ChatBot &&source);   //Move constructor

    ChatBot &operator=(ChatBot &&source)    //move assignment operator
    {
        std::cout << "ChatBot Move Assignment Operator" << std::endl;
        if(this == &source)
            return *this;

        _image = source._image;
        source._image = NULL;
        return *this;
    }

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
