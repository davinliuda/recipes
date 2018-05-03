<?php
/**
 * Auto generated from a.proto at 2018-03-17 00:43:04
 *
 * ProtoCS package
 */

namespace ProtoCS {
/**
 * MsgHead message
 */
class MsgHead extends \ProtobufMessage
{
    /* Field index constants */
    const CID = 1;

    /* @var array Field descriptors */
    protected static $fields = array(
        self::CID => array(
            'name' => 'cid',
            'required' => false,
            'type' => \ProtobufMessage::PB_TYPE_INT,
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
        $this->values[self::CID] = null;
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
     * Sets value of 'cid' property
     *
     * @param integer $value Property value
     *
     * @return null
     */
    public function setCid($value)
    {
        return $this->set(self::CID, $value);
    }

    /**
     * Returns value of 'cid' property
     *
     * @return integer
     */
    public function getCid()
    {
        $value = $this->get(self::CID);
        return $value === null ? (integer)$value : $value;
    }
}
}