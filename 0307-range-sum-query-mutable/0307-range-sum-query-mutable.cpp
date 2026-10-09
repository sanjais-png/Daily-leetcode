class NumArray {
public:

    vector<int>fenwick;
    vector<int>nums;  
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int size = nums.size();

        fenwick.assign(size+1 , 0);

        for(int i = 0 ;  i < size ; i++){
            build(i , nums[i]);
        }

        printFen();
    }

    void printFen(){
        for(int i = 0 ; i < fenwick.size() ; i++){
            cout << fenwick[i] <<" ";
        }
    }

    void build(int index, int val) {
        index += 1;
        while(index < this->fenwick.size()){
            fenwick[index] += val;
            index += (index & (-index));
        }
    }

    void update(int index, int val) {
        int replace = val;
        val = val - nums[index];
        index += 1;
        this->nums[index-1] = replace; 
        while(index < this->fenwick.size()){
            fenwick[index] += val;
            index += (index & (-index));
        }
    }
    
    int sum(int index){
        int s = 0;
        index += 1;
        while(index > 0){
            s += fenwick[index];
            index -= (index & (-index));
            //cout<<index<<" ";
        }
        //cout << endl;
        return s;
    }

    int sumRange(int left, int right) {
        return sum(right) - sum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */