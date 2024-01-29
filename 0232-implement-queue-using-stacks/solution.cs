public class MyQueue {
    private Stack<int> _pushStack, _popStack;
    public MyQueue() {
        _pushStack = new Stack<int>();
        _popStack = new Stack<int>();
    }
    private void Adjust(){
        if(_popStack.Count == 0){
            while(_pushStack.Count != 0){
                _popStack.Push(_pushStack.Peek());
                _pushStack.Pop();
            }
        }
    }
    public void Push(int x) {
        _pushStack.Push(x);
    }
    public int Pop() {
        int val = Peek();
        _popStack.Pop();
        return val;
    }
    public int Peek() {
        Adjust();
        return _popStack.Peek();
    }
    public bool Empty() {
        return (_pushStack.Count == 0 && _popStack.Count == 0);
    }
}
