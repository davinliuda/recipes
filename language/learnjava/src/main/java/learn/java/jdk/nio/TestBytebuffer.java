package learn.java.jdk.nio;

import java.nio.ByteBuffer;

/**
 * Created by liuda on 2017/4/13.
 */
public class TestBytebuffer {

    public static void main(String[] args) {
        byte[] b = new byte[1024];

        ByteBuffer b2 = ByteBuffer.wrap(b);

        System.out.println(b2.position());

        byte c = b2.get();

        System.out.println(c);

        System.out.println(b2.position());
    }
}
