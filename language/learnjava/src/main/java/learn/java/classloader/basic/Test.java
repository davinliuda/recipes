package learn.java.classloader.basic;

/**
 * Created by liuda on 2017/4/13.
 */
public class Test {

    public static void main(String[] args) {
        try {
            Person p = (Person) Class.forName("learn.java.classloader.basic.Person").newInstance();//Person p = new Person();
            p.print();

        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InstantiationException e) {
            e.printStackTrace();
        }
    }

}
