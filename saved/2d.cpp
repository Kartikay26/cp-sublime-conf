bool intersect(db x1, db y1, db x2, db y2, db x3, db y3, db x4, db y4, db &ret_x, db &ret_y){
	db v1x = x2-x1;
	db v1y = y2-y1;
	db v2x = x4-x3;
	db v2y = y4-y3;
	if(abs(v1x * v2y - v1y * v2x) < eps)
		return false;
	db a1 = x2 - x1;
	db a2 = x4 - x3;
	db b1 = y1 - y2;
	db b2 = y3 - y4;
	db c1 = y1*x2 - y2*x1;
	db c2 = y3*x4 - y4*x3;
	db det = a1*b2 - a2*b1;
	ret_x = (b2*c1 - b1*c2)/det;
	ret_y = (a1*c2 - a2*c1)/det;
	return true;
}
