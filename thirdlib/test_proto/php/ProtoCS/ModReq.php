<?php
/**
 * Auto generated from a.proto at 2018-03-17 00:43:04
 *
 * ProtoCS package
 */

namespace ProtoCS {
/**
 * ModReq message
 */
class ModReq extends \ProtobufMessage
{
    /* Field index constants */
    const B = 1;

    /* @var array Field descriptors */
    protected static $fields = array(
        self::B => array(
            'name' => 'b',
            'required' => false,
            'type' => \ProtobufMessage::PB_TYPE_BOOL,
        ),
    );

    /**
     * Constructs new message container and clears its internal state
     */
    public function __construct()
    {
        $this->reset();
    }

    /**
     * Clears message values and sets default ones
     *
     * @return null
     */
    public function reset()
    {
        $this->values[self::B] = null;
    }

    /**
     * Returns field descriptors
     *
     * @return array
     */
    public function fields()
    {
        return self::$fields;
    }

    /**
     * Sets value of 'b' property
     *
     * @param boolean $value Property value
     *
     * @return null
     */
    public function setB($value)
    {
        return $this->set(self::B, $value);
    }

    /**
     * Returns value of 'b' property
     *
     * @return boolean
     */
    public function getB()
    {
        $value = $this->get(self::B);
        return $value === null ? (boolean)$value : $value;
    }
}
}