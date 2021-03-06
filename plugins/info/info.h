#pragma once

#include <cstdint>

namespace dronecore {

class InfoImpl;

/**
 * @brief The Info class provides basic infomation about the hardware and/or software of a device.
 */
class Info
{
public:
    /**
     * @brief Constructor (internal use only).
     */
    explicit Info(InfoImpl *impl);

    /**
     * @brief Destructor (internal use only).
     */
    ~Info();

    /**
     * @brief Length of git hash strings.
     *
     * Length is 16 chars + null termination.
     */
    static const unsigned GIT_HASH_STR_LEN = 17;

    /**
     * @brief Type containing device version information.
     */
    struct Version {
        int flight_sw_major; /**< @brief Flight software major version. */
        int flight_sw_minor; /**<  @brief Flight software minor version. */
        int flight_sw_patch; /**<  @brief Flight software patch version. */
        int flight_sw_vendor_major; /**< @brief Flight software vendor major version. */
        int flight_sw_vendor_minor; /**< @brief Flight software vendor minor version. */
        int flight_sw_vendor_patch; /**< @brief Flight software vendor patch version. */
        char flight_sw_git_hash[GIT_HASH_STR_LEN]; /**< @brief Flight software git hash as string. */
        int os_sw_major; /**< @brief Operating system software major version. */
        int os_sw_minor; /**< @brief Operating system software minor version. */
        int os_sw_patch; /**< @brief Operating system software patch version. */
        char os_sw_git_hash[GIT_HASH_STR_LEN];/**< @brief Operating system software git hash as string. */
        uint16_t vendor_id; /**< @brief ID of board vendor. */
        uint16_t product_id; /**< @brief ID of product. */
    };

    /**
     * @brief Gets the UUID of the device.
     *
     * If possible this will be a unique identifier provided by hardware.
     *
     * @return The UUID of the device.
     */
    uint64_t uuid() const;

    /**
     * @brief Tests if this Version object is fully populated from hardware.
     *
     * @return `true` if Version object is fully populated from device.
     */
    bool is_complete() const;

    /**
     * @brief Get device version information.
     *
     * @return The version object for the device.
     */
    Version get_version() const;

    // Non-copyable
    /**
     * @brief Copy Constructor (object is not copyable).
     */
    Info(const Info &) = delete;
    /**
     * @brief Equality operator (object is not copyable).
     */
    const Info &operator=(const Info &) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    InfoImpl *_impl;
};

} // namespace dronecore
