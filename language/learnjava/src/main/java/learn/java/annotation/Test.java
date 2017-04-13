package learn.java.annotation;

import java.lang.annotation.Annotation;

/**
 * Created by liuda on 2017/4/13.
 */

@Person
public class Test {

    public static void print() throws ClassNotFoundException {
        Class clazz = Class.forName("learn.java.annotation.Person");

        Annotation[] annotations = clazz.getAnnotations();

        System.out.println("annotations:" + annotations.length);

        for(Annotation annotation: annotations){
            Person p = (Person)annotation;
            System.out.println(p.property());
        }
    }

    public static void  main(String[] args) throws ClassNotFoundException {
        Test.print();
    }
}
