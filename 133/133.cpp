//直接在github上创建
std::unordered_map<Node*,Node*> node_map;
Node* cloneGraph(Node* node)
{
    if (node == nullptr)
    {
        return node;
    }
    if (node_map.count(node))
        return node_map[node];
    Node* cloned_node = new Node(node.val);
    for ()
    {

    }

}
