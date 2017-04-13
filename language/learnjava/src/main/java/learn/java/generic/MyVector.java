package learn.java.generic;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by liuda on 2017/4/13.
 */
public class MyVector<E> {

    List<E> list = new ArrayList<E>();

    public void Add(E e){
        list.add(e);
    }

}
