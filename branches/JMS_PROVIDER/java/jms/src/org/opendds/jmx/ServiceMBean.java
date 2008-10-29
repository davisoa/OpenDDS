/*
 * $Id$
 */

package org.opendds.jmx;

/**
 * @author  Steven Stallion
 * @version $Revision$
 */
public interface ServiceMBean {

    boolean isActive();

    void start() throws Exception;

    void stop() throws Exception;

    void restart() throws Exception;
}
