function Car(x,y,Mov){
	this.Pos_X = x;
	this.Pos_Y = y;
	this.Mov_number = Mov;
	
}

Car.prototype.show = function(){
	fill(255,0,0);    
	stroke(0);
	console.log(this.Pos_Y);
    rect(40*this.Pos_X,40* this.Pos_Y, 19,1 9);



}