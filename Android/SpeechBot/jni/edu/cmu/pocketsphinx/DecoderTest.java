package edu.cmu.pocketsphinx;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

import org.junit.Test;


public class DecoderTest {
	static {
		System.loadLibrary("pocketsphinx_jni");
	}

	@Test
	public void testDecoder() {
		Decoder d = new Decoder();
		assertNotNull(d);
	}

	@Test
	public void testDecoderConfig() {
		Config c = new Config();
		c.setBoolean("-backtrace", true);
		Decoder d = new Decoder(c);
		assertNotNull(d);
	}

	@Test
	public void testGetConfig() {
		Decoder d = new Decoder();
		Config c = d.getConfig();
		assertNotNull(c);
		assertEquals(c.getString("-lmname"), "default");
	}
	
	@Test
	public void testDecodeRaw() {
		System.out.println("Called testDecodeRaw, which is unimplemented.");
	}
}
