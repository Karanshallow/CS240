


ShoppingCart::ShoppingCart(){
	newList = new LinkedList();
}
bool ShoppingCart::add(ItemToPurchase newItem){
	newList.append(newItem)
}
bool ShoppingCart::add(ItemToPurchase newItem,int position){
	if(!newList.insert(position, newItem)){
		cout<<"Position out of range: must be between 1 and "<<newList.getLength()<<endl;
		return false;
	}else{
		cout<<"Item added at position "<<position<<endl;
		return true;
	}
}
bool ShoppingCart::remove(int position){
	if(!newList.remove(position)){
		cout<<"Position out of range: must be between 1 and "<<newList.getLength()<<endl;
	}else{
		cout<<"Item added at position "position<<endl;
	}
void ShoppingCart::display(){
	for(int i =0;i<newList.getLength;i++){
		cout<<i+1<<'.'<<newList.retrieve(i+1).
