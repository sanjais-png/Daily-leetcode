class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>minQ;
    priority_queue<int>maxQ;
    int size;
    MedianFinder() {size = 0;}
    
    void addNum(int num) {
        size++;
        if(maxQ.empty()){
            maxQ.push(num);
        }else if(maxQ.top() >= num){
            maxQ.push(num);
        }else{
            minQ.push(num);
        }

        if(maxQ.size() > minQ.size()+1){
            minQ.push(maxQ.top());
            maxQ.pop();
        }else if(minQ.size() > maxQ.size()){
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }
    
    double findMedian() {
        if(maxQ.empty() && minQ.empty()){
            return 0;
        }

        if(minQ.size() < maxQ.size()){
            return maxQ.top();
        }else{
            return double(minQ.top() + maxQ.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */