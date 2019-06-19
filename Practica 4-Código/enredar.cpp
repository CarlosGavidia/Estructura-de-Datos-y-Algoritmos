void enredar () {
  Nodo* act = _prim;
  // Mientras que entre el nodo actual y el ultimo haya, al menos, un nodo ...
  while ((act != _ult)&&(act->_sig != _ult)) {  
	  Nodo *ai = _ult;  //Nodo a intercalar
	    //Se quita el nodo a intercalar del final
      _ult = _ult->_ant;  
      _ult->_sig = NULL;
            
	    // El siguiente del nodo a intercalar debe apuntar al 
	    // siguiente del actual
      ai->_sig = act->_sig;  
        // El anterior del nodo a intercalar debe apuntar al  
	    // actual
      ai->_ant = act;
		// El anterior del siguiente al actual debe apuntar al 
	    // nodo a intercalar
      act->_sig->_ant = ai;
	    // El siguiente del actual debe apuntar al nodo a intercalar
      act->_sig = ai;
		// El nodo a intercalar ya está colocado. Se avanza
	    // el actual al siguiente al de intercalar
      act = ai->_sig;		   
  }
}	
		