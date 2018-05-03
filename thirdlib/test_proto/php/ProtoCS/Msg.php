<?php
/**
 * Auto generated from a.proto at 2018-03-17 00:43:04
 *
 * ProtoCS package
 */

namespace ProtoCS {
/**
 * Msg message
 */
class Msg extends \ProtobufMessage
{
    /* Field index constants */
    const HEAD = 1;
    const RET_RET_RET = 2;
    const ID = 126;
    const MOD_REQ = 127;

    /* @var array Field descriptors */
    protected static $fields = array(
        self::HEAD => array(
            'name' => 'head',
            'required' => false,
            'type' => '\ProtoCS\MsgHead'
        ),
        self::RET_RET_RET => array(
            'name' => 'ret_ret_ret',
            'required' => false,
            'type' => \ProtobufMessage::PB_TYPE_INT,
        ),
        self::ID => array(
            'name' => 'id',
            'required' => false,
            'type' => \ProtobufMessage::PB_TYPE_INT,
        ),
        self::MOD_REQ => array(
            'name' => 'mod_req',
            'required' => false,
            'type' => '\ProtoCS\ModReq'
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
        $this->values[self::HEAD] = null;
        $this->values[self::RET_RET_RET] = null;
        $this->values[self::ID] = null;
        $this->values[self::MOD_REQ] = null;
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
     * Sets value of 'head' property
     *
     * @param \ProtoCS\MsgHead $value Property value
     *
     * @return null
     */
    public function setHead(\ProtoCS\MsgHead $value=null)
    {
        return $this->set(self::HEAD, $value);
    }

    /**
     * Returns value of 'head' property
     *
     * @return \ProtoCS\MsgHead
     */
    public function getHead()
    {
        return $this->get(self::HEAD);
    }

    /**
     * Sets value of 'ret_ret_ret' property
     *
     * @param integer $value Property value
     *
     * @return null
     */
    public function setRetRetRet($value)
    {
        return $this->set(self::RET_RET_RET, $value);
    }

    /**
     * Returns value of 'ret_ret_ret' property
     *
     * @return integer
     */
    public function getRetRetRet()
    {
        $value = $this->get(self::RET_RET_RET);
        return $value === null ? (integer)$value : $value;
    }

    /**
     * Sets value of 'id' property
     *
     * @param integer $value Property value
     *
     * @return null
     */
    public function setId($value)
    {
        return $this->set(self::ID, $value);
    }

    /**
     * Returns value of 'id' property
     *
     * @return integer
     */
    public function getId()
    {
        $value = $this->get(self::ID);
        return $value === null ? (integer)$value : $value;
    }

    /**
     * Sets value of 'mod_req' property
     *
     * @param \ProtoCS\ModReq $value Property value
     *
     * @return null
     */
    public function setModReq(\ProtoCS\ModReq $value=null)
    {
        return $this->set(self::MOD_REQ, $value);
    }

    /**
     * Returns value of 'mod_req' property
     *
     * @return \ProtoCS\ModReq
     */
    public function getModReq()
    {
        return $this->get(self::MOD_REQ);
    }
}
}
